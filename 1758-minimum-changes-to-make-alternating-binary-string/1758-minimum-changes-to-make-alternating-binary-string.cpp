class Solution {
public:
    int minOperations(string s) {
        int ok=0;
        int ok1=0;
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                if(s[i]=='0') ok++;
                else ok1++;
            }else{
                if(s[i]=='1') ok++;
                else ok1++;
            }
        }
        return s.length()-max(ok,ok1);
    }
};