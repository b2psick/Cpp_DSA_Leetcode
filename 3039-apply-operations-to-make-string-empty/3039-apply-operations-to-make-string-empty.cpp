class Solution {
public:
    string lastNonEmptyString(string s) {
        int max1=INT_MIN;
        unordered_map<int,int> mp;
        for(auto it:s){
            mp[it]++;
            max1=max(max1,mp[it]);
        }
        string ans="";
        unordered_map<int,int> mp1;
        for(auto it:s){
            mp1[it]++;
            if(mp1[it]==max1) ans+=it;
        }
        return ans;
    }
};