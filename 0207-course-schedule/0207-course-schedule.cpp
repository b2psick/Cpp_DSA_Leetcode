class Solution {
public:
    bool ok(int node,vector<vector<int>>& p,vector<int>& vis,vector<int>& pathv){
        vis[node]=1;
        pathv[node]=1;
        for(auto it:p[node]){
            if(!vis[it]){
                if(ok(it,p,vis,pathv)) return true;
            }else if(pathv[it]){
                return true;
            }
        }
        pathv[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        if(arr.size()==0) return true;
        vector<vector<int>> p(numCourses);
        for(int i=0;i<arr.size();i++){
            p[arr[i][0]].push_back(arr[i][1]);
        }
        vector<int> vis(numCourses);
        vector<int> pathv(numCourses);
        for(int i=0;i<p.size();i++){
            if(!vis[i]){
                if(ok(i,p,vis,pathv)) return false;
            }
        }
        return true;
    }
};