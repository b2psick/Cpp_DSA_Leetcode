class Solution {
public:
    int integerBreak(int n) {
        // int ans=1;
        // if(n==2) return 1;
        // if(n==3) return 2;
        // while(n!=0){
        //     if(n==6){
        //         ans=ans*9;
        //         break;
        //     }else if(n>=5){
        //         ans=ans*3;
        //         n-=3;
        //     }else{
        //         ans=ans*2;
        //         n-=2;
        //     }
        // }
        // return ans;
        if(n==1) return 1;
        if(n==2) return 1;
        if(n==3) return 2;
        int ans=1;
        if(n%3==0){
            ans=ans*pow(3,n/3);
        }else if(n%3==1){
            ans=ans*pow(3,n/3-1)*4;
        }else{
            ans=ans*pow(3,n/3)*2;
        }
        return ans;
    }
};