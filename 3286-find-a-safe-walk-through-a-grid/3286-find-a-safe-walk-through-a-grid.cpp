    class Solution {
    public:
        bool findSafeWalk(vector<vector<int>>& grid, int health) {
            priority_queue<pair<int,int>> pq;
            if(grid[0][0]==1) health--;
            vector<vector<int>> ok(grid.size(),vector<int>(grid[0].size(),-1));
            vector<pair<int,int>> dir;
            dir.push_back({1,0});
            dir.push_back({-1,0});
            dir.push_back({0,1});
            dir.push_back({0,-1});
            ok[0][0]=health;
            pq.push({health,0});
            while(!pq.empty()){
                if(pq.top().first<1) return false;
                int i=pq.top().second/grid[0].size();
                int j=pq.top().second%grid[0].size();
                int a=pq.top().first;
                pq.pop();
                if(a<ok[i][j]) continue;
                if(i==grid.size()-1&&j==grid[0].size()-1) return true;
                for(auto it:dir){
                    int ni=i+it.first;
                    int nj=j+it.second;
                    if(ni<0||nj<0||ni>=grid.size()||nj>=grid[0].size()) continue;
                    if(grid[ni][nj]==1){
                        if(ok[ni][nj]<a-1){
                            pq.push({a-1,ni*grid[0].size()+nj});
                            ok[ni][nj]=a-1;
                        }
                    }else{
                        if(ok[ni][nj]<a){
                            pq.push({a,ni*grid[0].size()+nj});
                            ok[ni][nj]=a;
                        }
                    }
                }
            }
            return false;
        }
    };