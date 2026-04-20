class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> ok(grid.size(),vector<int>(grid[0].size()));
        int ans=0;
        if(grid[0][0]==0){
            q.push({0,0});
            ok[0][0]=1;
        }
        vector<pair<int,int>> dir ={
            {0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,-1},{-1,1}
        };
        if(grid.size()==1&&grid[0].size()==1&&grid[0][0]==0) return 1;
        while(!q.empty()){
            ans++;
            int size=q.size();
            for(int k=0;k<size;k++){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto it:dir){
                int ni=i+it.first;
                int nj=j+it.second;
                if(ni<0||nj<0||ni>=grid.size()||nj>=grid[0].size()||grid[ni][nj]||ok[ni][nj]){
                    continue;
                }
                if(ni==grid.size()-1&&nj==grid[0].size()-1) return ans+1;
                ok[ni][nj]=1;
                q.push({ni,nj});
            }
            }
        }
        return -1;
    }
};