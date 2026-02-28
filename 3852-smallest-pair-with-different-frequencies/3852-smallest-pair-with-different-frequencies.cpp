class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int> ans(2);
        ans[0]=-1;
        ans[1]=-1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(mp[nums[i]]!=mp[nums[0]]){
                ans[0]=nums[0];
                ans[1]=nums[i];
                return ans;
            }
        }
        return ans;
    }
};