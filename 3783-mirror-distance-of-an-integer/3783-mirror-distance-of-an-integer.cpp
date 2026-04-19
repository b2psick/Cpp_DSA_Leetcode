class Solution {
public:
    int mirrorDistance(int n) {
        int p=n;
        int a=0;
        while(p!=0){
            a=a*10+p%10;
            p/=10;
        }
        return abs(n-a);
    }
};