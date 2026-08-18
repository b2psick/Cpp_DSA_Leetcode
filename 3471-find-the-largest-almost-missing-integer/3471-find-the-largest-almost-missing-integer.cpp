class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int max1 = -1;
        unordered_map<int, int> mp;
        int maxx = -1;
        for(auto it : nums) {
            mp[it]++;
            maxx = max(maxx, it);
        }
        if(k == 1) {
            for(auto it : mp) {
                if(it.second == 1) max1 = max(max1, it.first);
            }
            return max1;
        }
        if(k == nums.size()) return maxx;
        if(mp[nums[0]] == 1 && mp[nums[nums.size() - 1]] == 1) return max(nums[0], nums[nums.size() - 1]);
        if(mp[nums[0]] == 1) return nums[0];
        if(mp[nums[nums.size() - 1]] == 1) return nums[nums.size() - 1];
        return -1;
    }
};