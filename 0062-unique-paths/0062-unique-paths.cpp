class Solution {
public:

    //memo
    // int ok(int m1,int n1,vector<vector<int>>& dp){
    //     if(m1==dp.size()-1&&n1==dp[0].size()-1) return 1;
    //     if(m1>=dp.size()||n1>=dp[0].size()) return 0;
    //     if(dp[m1][n1]!=-1) return dp[m1][n1];
    //     int a=ok(m1+1,n1,dp);
    //     int b=ok(m1,n1+1,dp);
    //     dp[m1][n1]=a+b;
    //     return a+b;
    // }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return ok(0,0,dp);

        //tabulation
        vector<int> dp(n);
        dp[0]=1;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
};