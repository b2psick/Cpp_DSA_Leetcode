class Solution {
public:
    int ok(int n,vector<int>& vis){
        if(vis[n]!=-1) return vis[n];
        if(n==0) return 1;
        vis[n]=ok(n-1,vis);
        if(n>=2)
        vis[n]+=ok(n-2,vis);
        return vis[n];
    }
    int climbStairs(int n) {
        vector<int> vis(n+1,-1);
        return ok(n,vis);
    }
};