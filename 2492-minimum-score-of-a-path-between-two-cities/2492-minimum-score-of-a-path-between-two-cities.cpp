class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> ok(n);
        for(auto it:roads){
            ok[it[0]-1].push_back({it[2],it[1]-1});
            ok[it[1]-1].push_back({it[2],it[0]-1});
        }
        int min1=INT_MAX;
        queue<int> q;
        q.push(0);
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int a=q.front();
                q.pop();
                for(auto it:ok[a]){
                    if(dis[it.second]>it.first){
                        q.push(it.second);
                        dis[it.second]=it.first;
                        min1=min(min1,it.first);
                    }
                }
            }
        }
        return min1;
    }
};