    class Solution {
    public:
        bool dfs(vector<vector<int>>& graph,vector<int>& vis,vector<int>& pathv,stack<int>& st,int node,vector<int>& ans){
            if(ans[node]==-1) return true;
            vis[node]=1;
            pathv[node]=1;
            for(auto it:graph[node]){
                if(!vis[it]){
                if(dfs(graph,vis,pathv,st,it,ans)){
                    ans[node]=-1;
                    return true;
                }
                }
                else if(pathv[it]){
                    ans[node]=-1;
                    return true;
                }
            }
            pathv[node]=0;
            st.push(node);
            return false;
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            vector<int> vis(graph.size());
            stack<int> st;
            vector<int> pathv(graph.size());
            vector<int> ans(graph.size());
            for(int i=0;i<graph.size();i++){
                st={};
                if(!vis[i]||!(ans[i]==-1)){
                if(!dfs(graph,vis,pathv,st,i,ans)){
                    while(!st.empty()){
                        ans[st.top()]=1;
                        st.pop();
                    }
                }
                }
            }
            vector<int> ans1;
            for(int i=0;i<ans.size();i++){
                if(ans[i]==1) ans1.push_back(i);
            }
            return ans1;
        }
    };