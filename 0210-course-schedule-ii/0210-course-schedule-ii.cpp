class Solution {
public:
    bool ok(int node,vector<vector<int>>& p,vector<int>& vis,vector<int>& pathv,vector<int>& ans){   
        vis[node]=1;
        pathv[node]=1;
        for(auto it:p[node]){
            if(!vis[it]){
                if(ok(it,p,vis,pathv,ans)) return true;
            }else if(pathv[it]){
                return true;
            }
        }
        pathv[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& arr) {
        vector<vector<int>> p(numCourses);
        for(int i=0;i<arr.size();i++){
            p[arr[i][0]].push_back(arr[i][1]);
        }
        vector<int> vis(numCourses);
        vector<int> pathv(numCourses);
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            if(!vis[i]){
                if(ok(i,p,vis,pathv,ans)) return {};
            }
        }
        return ans;
    }
};