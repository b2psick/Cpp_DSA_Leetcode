class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> ok(26);
        vector<int> ok1(26);
        for(int i=0;i<word.size();i++){
            if(word[i]>='A'&&word[i]<='Z') ok1[word[i]-'A']++;
            else{
                ok[word[i]-'a']++;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(ok[i]&&ok1[i]) ans++; 
        }
        return ans;
    }
};