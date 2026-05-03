class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // vector<int> vis(n);
        // if(connections.size()<n-1) return -1;
        // vector<vector<int>> ok(n);
        // for(int i=0;i<connections.size();i++){
        //     ok[connections[i][0]].push_back(connections[i][1]);
        //     ok[connections[i][1]].push_back(connections[i][0]);
        // }
        // queue<int> q;
        // int a=0;
        // for(int i=0;i<vis.size();i++){
        //     if(!vis[i]){
        //         q.push(i);
        //         vis[i]++;
        //         a++;
        //     }
        //     while(!q.empty()){
        //         int size=q.size();
        //         for(int i=0;i<size;i++){
        //             int node=q.front();
        //             q.pop();
        //             for(auto it:ok[node]){
        //                 if(!vis[it]){
        //                     q.push(it);
        //                     vis[it]=1;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return a-1;

        //now using dsu
        if(connections.size()<n-1) return -1;
        DisjointSet ans(n);
        for(int i=0;i<connections.size();i++){
            ans.unionBySize(connections[i][0],connections[i][1]);
        }
        int a=0;
        for(int i=0;i<ans.parent.size()-1;i++){
            if(ans.parent[i]==i) a++;
        }
        return a-1;
    }
};