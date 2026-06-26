class Solution {
public:
    int ok(vector<int>& nums,int i,vector<int>& dp){
        if(i==0||i==1){
            return nums[i];
        }
        int max1=INT_MIN;
        if(dp[i]!=-1) return dp[i];
        if(i>2){
            max1=max(max1,ok(nums,i-3,dp));
        }
        max1=max(max1,ok(nums,i-2,dp));
        dp[i]=nums[i]+max1;
        return nums[i]+max1;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        if(nums.size()==1) return nums[0];
        int a=ok(nums,nums.size()-1,dp);
        int b=ok(nums,nums.size()-2,dp);
        return max(a,b);
    }
};