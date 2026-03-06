class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'&&!flag){
                flag=true;
            }else if(s[i]=='1'&&flag&&s[i-1]!='1'){
                return false;
            }
        }
        return true;
    }
};