class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int j=i;
            bool ok=false;
            bool ok1=false;
            while(j!=0){
                int k=j%10;
                if(k==0||k==1||k==8){
                }
                else if(k==2||k==5||k==6||k==9){
                    ok1=true;
                }else{
                    ok=true;
                    break;
                }
                j/=10;
            }
            if(ok1&&!ok) ans++;
        }
        return ans;
    }
};