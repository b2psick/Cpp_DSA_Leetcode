class Solution {
public:
    int ok(vector<int>& nums,int i,vector<int>& dp){
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int a=nums[i]+ok(nums,i-2,dp);
        int b=ok(nums,i-1,dp);
        dp[i]=max(a,b);
        return max(a,b);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return ok(nums,nums.size()-1,dp);
    }
};