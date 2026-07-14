class Solution {
public:

    // memoization
    // int ok(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
    //     if(grid[i][j]==1) return 0;
    //     if(i==grid.size()-1&&j==grid[0].size()-1){
    //         return 1;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int sum=0;
    //     if(i<grid.size()-1){
    //         sum+=ok(grid,dp,i+1,j);
    //     }
    //     if(j<grid[0].size()-1){
    //         sum+=ok(grid,dp,i,j+1);
    //     }
    //     dp[i][j]=sum;
    //     return sum;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        // return ok(grid,dp,0,0);

        vector<int> dp(grid[0].size());
        dp[0]=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int p=0;
                if(j>0){
                    p=dp[j-1];
                }
                if(grid[i][j]!=1){
                    dp[j]+=p;
                }else{
                    dp[j]=0;
                }
            }
        }
        return dp[dp.size()-1];
    }
};