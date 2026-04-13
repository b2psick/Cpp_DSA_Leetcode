class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(auto it:cpdomains){
            int i=0;
            string ok="";
            while(it[i]!=' '){
                ok+=it[i];
                i++;
            }
            int j=stoi(ok);
            string p="";
            i=it.length()-1;
            while(it[i]!=' '){
                if(it[i]=='.'){
                    mp[p]+=j;
                }
                p+=it[i];
                i--;
            }
            mp[p]+=j;
        }
        for(auto it:mp){
            string ans1="";
            ans1+=to_string(it.second);
            ans1+=' ';
            string s=it.first;
            reverse(s.begin(),s.end());
            ans1+=s;
            ans.push_back(ans1);
        }
        return ans;
    }
};