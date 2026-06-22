class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max1=INT_MIN;
        for(auto it:costs) max1=max(max1,it);
        vector<int> ok(max1+1);
        for(auto it:costs) ok[it]++;
        for(int i=1;i<ok.size();i++){
            ok[i]=ok[i]+ok[i-1];
        }
        vector<int> sorted;
        int a=0;
        for(int i=0;i<ok.size();i++){
            for(int j=0;j<ok[i]-a;j++){
                sorted.push_back(i);
            }
            a=ok[i];
        }
        int ans=0;
        for(auto it:sorted){
            if(coins<it){
                return ans;
            }
            coins-=it;
            ans++;
        }
        return ans;
    }
};