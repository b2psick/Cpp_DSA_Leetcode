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
    int largestIsland(vector<vector<int>>& grid) {
        int max1=0;
        DisjointSet ok(grid.size()*grid.size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    if(i<grid.size()-1&&grid[i+1][j]==1){
                        if(ok.findUPar(i*grid.size()+j)!=ok.findUPar((i+1)*grid.size()+j)){
                            ok.unionBySize(i*grid.size()+j,(i+1)*grid.size()+j);
                        }
                    }
                    if(j<grid.size()-1&&grid[i][j+1]==1){
                        if(ok.findUPar(i*grid.size()+j)!=ok.findUPar(i*grid.size()+j+1)){
                            ok.unionBySize(i*grid.size()+j,i*grid.size()+j+1);
                        }
                    }
                }
            }
        }
        bool ok1=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                int sum=0;
                unordered_set<int> set;
                if(grid[i][j]==0){
                    ok1=true;
                    if(i>0&&grid[i-1][j]==1){
                        set.insert(ok.findUPar((i-1)*grid.size()+j));
                    }
                    if(i<grid.size()-1&&grid[i+1][j]==1){
                        set.insert(ok.findUPar((i+1)*grid.size()+j));
                    }
                    if(j>0&&grid[i][j-1]==1){
                        set.insert(ok.findUPar(i*grid.size()+j-1));
                    }
                    if(j<grid.size()-1&&grid[i][j+1]==1){
                        set.insert(ok.findUPar(i*grid.size()+j+1));
                    }
                }
                for(auto it:set){
                    sum+=ok.size[it];
                }
                max1=max(max1,sum);
            }
        }
        if(!ok1) return grid.size()*grid.size();
        return max1+1;
    }
};