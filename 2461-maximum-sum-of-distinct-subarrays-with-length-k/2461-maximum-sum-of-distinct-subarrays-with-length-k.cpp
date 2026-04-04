class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left=0;
        long long ans=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            sum+=nums[i];
            if(mp[nums[i]]==2){
                while(left<i&&mp[nums[i]]==2){
                    if(mp[nums[left]]==1) mp.erase(nums[left]);
                    else mp[nums[left]]--;
                    sum-=nums[left];
                    left++;
                }
            }
            while(left<i&&mp.size()>k){
                if(mp[nums[left]]==1) mp.erase(nums[left]);
                else mp[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            if(mp.size()==k&&i-left+1==k){
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};