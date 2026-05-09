class Solution {
public:
    void dfs(vector<vector<int>>& ok,vector<int>& vis,int node){
        vis[node]=1;
        for(auto it:ok[node]){
            if(!vis[it]){
                dfs(ok,vis,it);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        vector<vector<int>> ok(stones.size());
        for(int i=0;i<stones.size();i++){
            if(mp1.find(stones[i][0])!=mp1.end()){
                ok[mp1[stones[i][0]]].push_back(i);
                ok[i].push_back(mp1[stones[i][0]]);
            }else{
                mp1[stones[i][0]]=i;
            }
            if(mp2.find(stones[i][1])!=mp2.end()){
                ok[mp2[stones[i][1]]].push_back(i);
                ok[i].push_back(mp2[stones[i][1]]);
            }else{
                mp2[stones[i][1]]=i;
            }
        }
        vector<int> vis(stones.size());
        int a=0;
        for(int i=0;i<stones.size();i++){
            if(!vis[i]){
                dfs(ok,vis,i);
                a++;
            }
        }
        return stones.size()-a;
    }
};