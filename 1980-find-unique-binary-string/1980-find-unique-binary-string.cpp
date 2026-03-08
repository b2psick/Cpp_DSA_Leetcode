class Solution {
public:
    bool ok(string& p,string& ans,unordered_set<string>& set){
        if(p.size()==set.size()){
            if(set.find(p)==set.end()){
                ans=p;
                return true;
            }else{
                return false;
            }
        }
        p+='1';
        if(ok(p,ans,set)) return true;
        p.pop_back();
        p+='0';
        if(ok(p,ans,set)) return true;
        p.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
       unordered_set<string> set;
       for(auto it:nums) set.insert(it);
       string ans="";
       string p="";
       ok(p,ans,set);
       return ans; 
    }
};