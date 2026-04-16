class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum=0;
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i>=2*k){
                ans[i-k]=sum/(2*k+1);
                sum-=nums[i-2*k];
            }
        }
        return ans;
    }
};