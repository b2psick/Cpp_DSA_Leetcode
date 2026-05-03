class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string a=s+s;
        for(int i=0;i<a.size()-goal.size();i++){
            if(a.substr(i,goal.size())==goal) return true;
        }   
        return false;
    }
};