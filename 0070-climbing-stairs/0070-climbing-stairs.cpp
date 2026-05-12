class Solution {
public:
    int ok(int n,vector<int>& vis){
        if(vis[n]!=-1) return vis[n];
        if(n==0) return 1;
        vis[n]=ok(n-1,vis);
        if(n>=2)
        vis[n]+=ok(n-2,vis);
        return vis[n];
    } //memoization

    int climbStairs(int n) {
        int a=1;
        int b=1;
        int c=1;
        //tabulation with space optimization
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};