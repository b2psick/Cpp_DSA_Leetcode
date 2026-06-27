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
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int a=nums[0];
        int b=max(nums[0],nums[1]);
        int c=0;
        for(int i=2;i<nums.size();i++){
            c=max(b,nums[i]+a);
            a=b;
            b=c;
        }
        return c;
    }
};