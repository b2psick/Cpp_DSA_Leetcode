class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min1 = INT_MAX;
        int max1 = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            min1 = min(min1, nums[i]);
            max1 = max(max1, nums[i]);
        }

        vector<int> count(max1 - min1 + 1);
        for(auto it : nums) {
            count[it-min1]++;
        }

        vector<int> ans;
        for(int i = 0; i < count.size(); i++) {
            if(count[i] == 0) {
                ans.push_back(i + min1);
            }
        }
        return ans;
    }
};