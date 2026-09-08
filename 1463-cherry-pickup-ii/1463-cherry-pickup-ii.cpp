class Solution {
public:

    //memo

    // int maxCherry(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
    //     if(j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()) return 0;

    //     if(i == grid.size() - 1) {
    //         if(j1 == j2) {
    //             return grid[i][j1];
    //         }
    //         return grid[i][j1] + grid[i][j2];
    //     }
        
    //     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    //     int maxHere = 0;

    //     for(int k = -1; k < 2; k++) {
    //         for(int j = -1; j < 2; j++) {
    //             int val = maxCherry(grid, i + 1, j1 + k, j2 + j, dp);
    //             if(j1 == j2) maxHere = max(maxHere, grid[i][j1] + val);
    //             else maxHere = max(maxHere, grid[i][j1] + grid[i][j2] + val);
    //         }
    //     }

    //     dp[i][j1][j2] = maxHere;

    //     return maxHere;
    // }

    int cherryPickup(vector<vector<int>>& grid) {
        // vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        // return maxCherry(grid, 0, 0, grid[0].size() - 1, dp);

        // tabulation

        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), INT_MIN)));
        int ans = 0;

        for(int i = 0; i < grid.size(); i++) {
            if(i == 0) {
                if(grid[0].size() == 1) dp[0][0][0] = grid[0][0];
                else dp[0][0][grid[0].size() - 1] = grid[0][0] + grid[0][grid[0].size() - 1];
                if(i == grid.size() - 1) ans = max(ans, dp[0][0][grid[0].size() - 1]);
                continue;
            }
            for(int j1 = 0; j1 < grid[0].size(); j1++) {
                for(int j2 = 0; j2 < grid[0].size(); j2++) {
                    for(int k = -1; k < 2; k++) {
                        for(int h = -1; h < 2; h++) {
                            if(j1 + k < 0 || j1 + k >= grid[0].size() || j2 + h < 0 || j2 + h >= grid[0].size()) continue;
                            if(j1 == j2) {
                                dp[i][j1][j2] = max(dp[i][j1][j2], grid[i][j1] + dp[i - 1][j1 + k][j2 + h]); 
                            }else {
                                dp[i][j1][j2] = max(dp[i][j1][j2], grid[i][j1] + grid[i][j2] + dp[i - 1][j1 + k][j2 + h]); 
                            }
                            ans = max(ans, dp[i][j1][j2]);
                        }
                    }
                }
            }
        }

        return ans;
    }
};