class Solution {
public:
    int a=1;
    void dfs(vector<vector<int>>& ok,vector<vector<int>>& ans,int node,int parent,vector<int>& vis,vector<int>& tim,vector<int>& low){
        vis[node]=1;
        tim[node]=low[node]=a;
        a++;
        for(auto it:ok[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(ok,ans,it,node,vis,tim,low);
                low[node]=min(low[node],low[it]);
                if(low[it]>tim[node]){
                    ans.push_back({it,node});
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ok(n);
        for(int i=0;i<connections.size();i++){
            ok[connections[i][0]].push_back(connections[i][1]);
            ok[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> ans;
        vector<int> vis(n);
        vector<int> tim(n);
        vector<int> low(n);
        dfs(ok,ans,0,-1,vis,tim,low);
        return ans;
    }
};