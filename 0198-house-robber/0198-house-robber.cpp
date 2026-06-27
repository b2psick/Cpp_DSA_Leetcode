class Solution {
public:

    //memoization
    // int ok(vector<int>& nums,int i,vector<int>& dp){
    //     if(i==0) return nums[0];
    //     if(i<0) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int a=nums[i]+ok(nums,i-2,dp);
    //     int b=ok(nums,i-1,dp);
    //     dp[i]=max(a,b);
    //     return max(a,b);
    // }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return ok(nums,nums.size()-1,dp);

        //tabulation
        vector<int> dp(nums.size());
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[dp.size()-1];
    }
};