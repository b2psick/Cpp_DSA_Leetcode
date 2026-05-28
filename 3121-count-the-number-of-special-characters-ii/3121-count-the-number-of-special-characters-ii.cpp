class Solution {
public:
    int numberOfSpecialChars(string word){
        vector<int> ok(26,INT_MAX);
        vector<int> ok1(26,-1);
        for(int i=0;i<word.size();i++){
            if(word[i]>='A'&&word[i]<='Z'&&ok1[word[i]-'A']==-1) ok1[word[i]-'A']=i;
            else if(word[i]>='a'&&word[i]<='z'){
                ok[word[i]-'a']=i;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(ok[i]<ok1[i]) ans++;
        }
        return ans;
    }
};