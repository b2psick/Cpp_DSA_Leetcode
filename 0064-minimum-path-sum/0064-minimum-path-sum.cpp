class Solution {
public:
    int ok(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i==grid.size()-1&&j==grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int sum=INT_MAX;
        if(i+1<=grid.size()-1){
            sum=min(sum,ok(grid,i+1,j,dp));
        }
        if(j+1<=grid[0].size()-1){
            sum=min(sum,ok(grid,i,j+1,dp));
        }
        sum+=grid[i][j];
        dp[i][j]=sum;
        return sum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return ok(grid,0,0,dp);
    }
};