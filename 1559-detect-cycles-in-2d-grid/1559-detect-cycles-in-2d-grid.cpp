class Solution {
public:
    bool dfs(vector<vector<char>>& grid,int i,int j,int pi,int pj,vector<vector<int>>& vis){
        if(pi==-1||pj==-1){
            
        }
        else if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]!=grid[pi][pj]) return false;
        if(vis[i][j]==1) return true;
        vis[i][j]=1;
        if(i-1!=pi)
        if(dfs(grid,i-1,j,i,j,vis)) return true;
        if(i+1!=pi)
        if(dfs(grid,i+1,j,i,j,vis)) return true;
        if(j-1!=pj)
        if(dfs(grid,i,j-1,i,j,vis)) return true;
        if(j+1!=pj)
        if(dfs(grid,i,j+1,i,j,vis)) return true;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]){
                    if(dfs(grid,i,j,-1,-1,vis)) return true;
                }
            }
        }
        return false;
    }
};