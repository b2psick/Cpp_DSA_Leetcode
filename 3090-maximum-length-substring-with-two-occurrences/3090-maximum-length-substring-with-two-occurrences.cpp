class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int left = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            if(mp[s[i]] > 2) {
                while(left < i && mp[s[i]] > 2) {
                    mp[s[left]]--;
                    left++;
                }
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};