class Solution {
public:
    bool isPowerOfFour(int n) {
        if(((long long)n&(long long)n-1)!=0) return false;
        while(n){
            if(n==1) return true;
            if(n==4) return true;
            if(n==2) return false;
            n=n/4;
        }
        return false;
    }
};