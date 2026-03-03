class Solution {
public:
    char findKthBit(int n, int k) {
        string ok="0";
        for(int i=0;i<n-1;i++){
            string b="";
            for(int i=0;i<ok.size();i++){
                if(ok[i]=='0') b+='1';
                else b+='0';
            }
            reverse(b.begin(),b.end());
            ok+='1';
            ok+=b;
            if(k<=ok.size()) return ok[k-1];
        }
        return ok[k-1];
    }
};