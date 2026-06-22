class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max1=INT_MIN;
        for(auto it:costs) max1=max(max1,it);
        vector<int> ok(max1+1);
        for(auto it:costs) ok[it]++;
        int a=0;
        int ans=0;
        for(int i=1;i<ok.size();i++){
            if((long long)i*(long long)ok[i]>coins){
                if(coins==0) return ans;
                ans+=coins/i;
                return ans;
            }
            ans+=ok[i];
            coins-=i*ok[i];
        }
        return ans;
    }
};