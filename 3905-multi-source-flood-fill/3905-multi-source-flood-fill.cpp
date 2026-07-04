class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<int> q;
        vector<vector<int>> ok(n,vector<int>(m));
        for(auto it:sources){
            ok[it[0]][it[1]]=it[2];
            q.push(it[0]*m+it[1]);
        }
        vector<pair<int,int>> dir;
        dir.push_back({0,1});
        dir.push_back({1,0});
        dir.push_back({-1,0});
        dir.push_back({0,-1});
        while(!q.empty()){
            int size=q.size();
            unordered_set<int> set;
            for(int k=0;k<size;k++){
                int i=q.front()/m;
                int j=q.front()%m;
                int c=ok[i][j];
                q.pop();
                for(auto it:dir){
                    int ni=i+it.first;
                    int nj=j+it.second;
                    if(ni<0||nj<0||ni>=n||nj>=m) continue;
                    if(ok[ni][nj]==0){
                        ok[ni][nj]=c;
                        set.insert(ni*m+nj);
                        q.push(ni*m+nj);
                    }else{
                        if(ok[ni][nj]>c) continue;
                        else if(set.find(ni*m+nj)!=set.end()){
                            ok[ni][nj]=c;
                        }
                    }
                }
            }
        }
        return ok;
    }
};