class Solution {
public:
    long long sumAndMultiply(int n) {
        long long p=0;
        long long sum=0;
        while(n!=0){
            if(n%10!=0){
                p=p*10+n%10;
                sum+=n%10;
            }
            n=n/10;
        }
        while(p!=0){
            n=n*10+p%10;
            p=p/10;
        }
        return n*sum;
    }
};