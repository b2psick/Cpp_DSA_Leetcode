class Solution {
public:
    int ok(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
        if(grid[i][j]==1) return 0;
        if(i==grid.size()-1&&j==grid[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int sum=0;
        if(i<grid.size()-1){
            sum+=ok(grid,dp,i+1,j);
        }
        if(j<grid[0].size()-1){
            sum+=ok(grid,dp,i,j+1);
        }
        dp[i][j]=sum;
        return sum;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return ok(grid,dp,0,0);
    }
};