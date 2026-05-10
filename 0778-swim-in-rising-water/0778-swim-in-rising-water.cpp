class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> ok(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        ok[0][0]=grid[0][0];
        pq.push({grid[0][0],0});
        while(!pq.empty()){
            int max1=pq.top().first;
            int i=pq.top().second/grid[0].size();
            int j=pq.top().second%grid[0].size();
            pq.pop();
            if(ok[i][j]<max1) continue;
            if(i>0&&max(max1,grid[i-1][j])<ok[i-1][j]){
                ok[i-1][j]=max(max1,grid[i-1][j]);
                pq.push({max(max1,grid[i-1][j]),(i-1)*grid[0].size()+j});
            }
            if(i<grid.size()-1&&max(max1,grid[i+1][j])<ok[i+1][j]){
                ok[i+1][j]=max(max1,grid[i+1][j]);
                pq.push({max(max1,grid[i+1][j]),(i+1)*grid[0].size()+j});
            }
            if(j>0&&max(max1,grid[i][j-1])<ok[i][j-1]){
                ok[i][j-1]=max(max1,grid[i][j-1]);
                pq.push({max(max1,grid[i][j-1]),i*grid[0].size()+j-1});
            }
            if(j<grid[0].size()-1&&max(max1,grid[i][j+1])<ok[i][j+1]){
                ok[i][j+1]=max(max1,grid[i][j+1]);
                pq.push({max(max1,grid[i][j+1]),i*grid[0].size()+j+1});
            }
        }
        return ok[grid.size()-1][grid[0].size()-1];
    }
};