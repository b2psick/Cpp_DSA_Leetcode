class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        priority_queue<pair<int,int>> pq;
        vector<vector<int>> ok(n,vector<int>(m));
        for(auto it:sources){
            ok[it[0]][it[1]]=it[2];
            pq.push({it[2],it[0]*m+it[1]});
        }
        vector<pair<int,int>> dir;
        dir.push_back({0,1});
        dir.push_back({1,0});
        dir.push_back({-1,0});
        dir.push_back({0,-1});
        while(!pq.empty()){
            int size=pq.size();
            queue<pair<int,int>> q;
            for(int k=0;k<size;k++){
                int i=pq.top().second/m;
                int j=pq.top().second%m;
                int c=pq.top().first;
                pq.pop();
                for(auto it:dir){
                    int ni=i+it.first;
                    int nj=j+it.second;
                    if(ni<0||nj<0||ni>=n||nj>=m) continue;
                    if(ok[ni][nj]==0){
                        ok[ni][nj]=c;
                        q.push({c,ni*m+nj});
                    }
                }
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
        return ok;
    }
};