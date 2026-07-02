class Solution {
public:

    //memoization
    // int ok(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
    //     if(i==grid.size()-1&&j==grid[0].size()-1){
    //         return grid[i][j];
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int sum=INT_MAX;
    //     if(i+1<=grid.size()-1){
    //         sum=min(sum,ok(grid,i+1,j,dp));
    //     }
    //     if(j+1<=grid[0].size()-1){
    //         sum=min(sum,ok(grid,i,j+1,dp));
    //     }
    //     sum+=grid[i][j];
    //     dp[i][j]=sum;
    //     return sum;
    // }
    int minPathSum(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        // return ok(grid,0,0,dp);

        //tabulation
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        dp[0][0]=grid[0][0];
        for(int i=1;i<grid.size();i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int i=1;i<grid[0].size();i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};