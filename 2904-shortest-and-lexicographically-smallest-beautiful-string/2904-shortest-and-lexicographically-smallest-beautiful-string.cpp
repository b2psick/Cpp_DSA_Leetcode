class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        for(auto it : s) ans += '1';

        int left = 0;
        int ones = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') ones++;
            string curr = "";
            bool starting = true;
            while(left < i && ones > k) {
                if(s[left] == '1') ones--;
                left++;
            }
            if(ones == k) {
                for(int j = left; j <= i; j++) {
                    if(s[j] == '1') starting = false;
                    if(starting && s[j] == '0') continue; 
                    curr += s[j];
                }
                if(curr.size() < ans.size()) ans = curr;
                if(curr.size() == ans.size() && curr < ans) ans = curr;
            }
        }
        return ones == k ? ans : "";
    }
};