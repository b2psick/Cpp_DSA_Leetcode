class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > k) {
                while(left < i && mp[nums[i]] > k) {
                    mp[nums[left]]--;
                    left++;
                }
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};