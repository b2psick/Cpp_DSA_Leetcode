class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        string ans="";
        string p="";
        for(auto it:knowledge) mp[it[0]]=it[1];
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                flag=true;
            }else if(s[i]==')'){
                flag=false;
                if(mp.find(p)==mp.end()) ans+='?';
                else ans+=mp[p];
                p="";
            }else if(flag){
                p+=s[i];
            }else ans+=s[i];
        }
        return ans;
    }
};