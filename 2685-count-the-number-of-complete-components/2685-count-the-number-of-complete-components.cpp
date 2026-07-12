class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ok(n);
        for(auto it:edges){
            ok[it[0]].push_back(it[1]);
            ok[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        vector<vector<int>> comp;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> k;
                comp.push_back(k);
                q.push(i);
                vis[i]=1;
            }
            while(!q.empty()){
                int a=q.front();
                comp.back().push_back(a);
                q.pop();
                for(auto it:ok[a]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        int ans=0;
        for(auto it:comp){
            bool p=false;
            for(auto it1:it){
                if(ok[it1].size()<it.size()-1){
                    p=true;
                }
            }
            if(!p) ans++;
        }
        return ans;
    }
};