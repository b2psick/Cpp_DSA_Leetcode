class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> set;
        long long ans=1<<k;
        for(int i=0;i<s.length()-k+1;i++){
            if(s.length()-i<k) break;
            set.insert(s.substr(i,k));
        }
        if(set.size()==ans) return true;
        return false;
    }
};