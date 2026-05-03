class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> vis(n);
        if(connections.size()<n-1) return -1;
        vector<vector<int>> ok(n);
        for(int i=0;i<connections.size();i++){
            ok[connections[i][0]].push_back(connections[i][1]);
            ok[connections[i][1]].push_back(connections[i][0]);
        }
        queue<int> q;
        int a=0;
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                q.push(i);
                vis[i]++;
                a++;
            }
            while(!q.empty()){
                int size=q.size();
                for(int i=0;i<size;i++){
                    int node=q.front();
                    q.pop();
                    for(auto it:ok[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
            }
        }
        return a-1;
    }
};