class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        string ans="";
        while(mp[y]){
            ans+=y;
            mp[y]--;
        }
        for(auto it:mp){
            for(int i=0;i<it.second;i++){
                ans+=it.first;
            }
        }
        return ans;
    }
};