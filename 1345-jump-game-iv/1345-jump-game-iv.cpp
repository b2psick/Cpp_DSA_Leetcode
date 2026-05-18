class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> vis(arr.size());
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int ans=0;
        while(!q.empty()){
            ans++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int a=q.front();
                if(a==arr.size()-1) return ans-1;
                q.pop();
                if(a>0&&!vis[a-1]){
                    q.push(a-1);
                    vis[a-1]=1;
                }
                if(a<arr.size()-1&&!vis[a+1]){
                    q.push(a+1);
                    vis[a+1]=1;
                }
                for(int j=0;j<mp[arr[a]].size();j++){
                    if(!vis[mp[arr[a]][j]]){
                        q.push(mp[arr[a]][j]);
                        vis[mp[arr[a]][j]]=1;
                    }
                }
                mp[arr[a]].clear();
            }
        }
        return ans-1;
    }
};