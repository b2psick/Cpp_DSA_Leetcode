class Solution {
public:
    bool ok(int node,int color,vector<int>& p,vector<vector<int>>& graph){
        p[node]=color;
        for(auto it:graph[node]){
            if(p[it]==-1){
                if(!ok(it,!color,p,graph)) return false;
            }else if(p[it]==color) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> p(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(p[i]==-1){
                if(!ok(i,0,p,graph)) return false;
            }
        }
        return true;
    }
};