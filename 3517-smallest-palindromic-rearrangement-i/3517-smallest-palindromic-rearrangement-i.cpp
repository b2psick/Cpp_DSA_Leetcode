class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> characters(26);
        char midChar = '0';
        
        for(int i = 0; i < s.length(); i++) {
            characters[s[i] - 'a']++;
        }
        for(int i = 0; i < characters.size(); i++) {
            if(characters[i] == 1) midChar = i + 'a';
        }
        
        string ans = "";
        for(int i = 0; i < characters.size(); i++) {
            if(i + 'a' != midChar) {
                for(int j = 0; j < characters[i]/2; j++) {
                    ans += i + 'a';
                }
            }
        }
        string copy = ans;
        reverse(copy.begin(), copy.end());

        for(int i = 0; i < characters.size(); i++) {
            if(i + 'a' != midChar && characters[i] % 2 != 0) {
                ans += i + 'a';
            }
        }        

        if(midChar != '0') {
            ans += midChar;
        }
        if(s.size() != 1) {
            ans += copy;
        }
        return ans;
    }
};