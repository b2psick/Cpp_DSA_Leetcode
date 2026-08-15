class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int allXor = 0;
        for(auto it : nums) allXor ^= it;
        if(allXor != 0) return nums.size();
        for(auto it : nums) {
            if(allXor ^ it != 0) return nums.size() - 1;
        }
        return 0;
    }
};