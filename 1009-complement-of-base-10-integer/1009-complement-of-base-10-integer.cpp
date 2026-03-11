class Solution {
public:
    int bitwiseComplement(int n) {
        int p=0;
        if(n==0) return 1;
        int count=1;
        while(n!=0){
            if(n%2==0) p+=count;
            else p+=0;
            n=n/2;
            count=count*2;
        }
        return p;
    }
};