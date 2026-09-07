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
        
        vector<int> dp(grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0) {
                    dp[j] = grid[0][0];
                    continue;
                }
                else if(i==0) {
                    dp[j] = grid[i][j] + dp[j-1];
                    continue; 
                }    
            
                if(j == 0) {
                    dp[j] += grid[i][0];
                }else{
                    dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
                }
            }
        }
        return dp[dp.size()-1];
    }
};