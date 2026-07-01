class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<int> q;
        vector<vector<int>> dis(grid.size(),vector<int>(grid.size()));
        vector<vector<int>> vis(grid.size(),vector<int>(grid.size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    q.push(i*grid.size()+j);
                    vis[i][j]=1;
                }
            }
        }
        if(grid[0][0]==1||grid[grid.size()-1][grid.size()-1]==1) return 0;
        vector<pair<int,int>> dir;
        dir.push_back({0,1});
        dir.push_back({1,0});
        dir.push_back({-1,0});
        dir.push_back({0,-1});
        int a=0;
        int st=INT_MAX;
        int ed=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            a++;
            for(int k=0;k<size;k++){
                int i=q.front()/grid.size();
                int j=q.front()%grid.size();
                q.pop();
                for(auto it:dir){
                    int ni=i+it.first;
                    int nj=j+it.second;
                    if(ni<0||ni>=grid.size()||nj<0||nj>=grid.size()||vis[ni][nj]) continue;
                    q.push(ni*grid.size()+nj);
                    vis[ni][nj]=1;
                    dis[ni][nj]=a;
                    st=min(st,dis[ni][nj]);
                    ed=max(ed,dis[ni][nj]);
                }
            }
        }
        int ans=0;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            queue<int> q1;
            vector<vector<int>> vis1(grid.size(),vector<int>(grid.size()));
            q1.push(0);
            vis1[0][0]=1;
            bool h=false;
            while(!q1.empty()){
                int size=q1.size();
                for(int k=0;k<size;k++){
                    int i=q1.front()/grid.size();
                    int j=q1.front()%grid.size();
                    q1.pop();
                    if(dis[i][j]<mid) continue;
                    for(auto it:dir){
                        int ni=i+it.first;
                        int nj=j+it.second;
                        if(ni<0||ni>=grid.size()||nj<0||nj>=grid.size()||vis1[ni][nj]||dis[ni][nj]<mid||grid[ni][nj]==1) continue;
                        q1.push(ni*grid.size()+nj);
                        vis1[ni][nj]=1;
                        if(ni==grid.size()-1&&nj==grid.size()-1){
                            h=true;
                            break;
                        }
                    }
                    if(h==true) break;
                }
                if(h==true) break;
            }
            if(h==true){
                st=mid+1;
                ans=max(ans,mid);
            }else ed=mid-1;
        }
        return ans;
    }
};