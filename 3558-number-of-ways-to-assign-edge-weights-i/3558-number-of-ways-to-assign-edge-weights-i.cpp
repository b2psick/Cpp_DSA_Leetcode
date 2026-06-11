class Solution {
public:
    int ok(int node,vector<vector<int>>& adj,vector<int>& vis){
        int max1=0;
        vis[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]])
            max1=max(max1,ok(adj[node][i],adj,vis));
        }
        return 1+max1;
    }
    long long pow1(int a){
        if(a<0) return 0;
        if(a==0) return 1;
        if(a==1) return 2;
        if(a%2==0){
            long long b=pow1(a/2)%1000000007;
            return (b*b)%1000000007;
        }
        return (2*pow1(a-1)%1000000007)%1000000007;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<int> vis(edges.size()+2,0);
        vector<vector<int>> adj(edges.size()+2);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int a=ok(1,adj,vis)-1;
        return pow1(a-1);
    }
};