class Solution {
public:
    int maxCherry(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
        if(j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()) return 0;

        if(i == grid.size() - 1) {
            if(j1 == j2) {
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxHere = 0;

        for(int k = -1; k < 2; k++) {
            for(int j = -1; j < 2; j++) {
                int val = maxCherry(grid, i + 1, j1 + k, j2 + j, dp);
                if(j1 == j2) maxHere = max(maxHere, grid[i][j1] + val);
                else maxHere = max(maxHere, grid[i][j1] + grid[i][j2] + val);
            }
        }

        dp[i][j1][j2] = maxHere;

        return maxHere;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return maxCherry(grid, 0, 0, grid[0].size() - 1, dp);
    }
};