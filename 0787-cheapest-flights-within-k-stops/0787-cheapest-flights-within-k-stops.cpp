class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<pair<int,int>>> ok(n);
        for(int i=0;i<flights.size();i++){
            ok[flights[i][0]].push_back({flights[i][2],flights[i][1]});
        }
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        pq.push({0,src,0});
        dist[src][0]=0;
        while(!pq.empty()){
            auto [wt,node,stop]=pq.top();
            pq.pop();
            if(node==dst) return wt;
            if(stop>k) continue;
            if(dist[node][stop]<wt) continue;
            for(auto it:ok[node]){
                if(wt+it.first<dist[it.second][stop+1]){
                    dist[it.second][stop+1]=wt+it.first;
                    pq.push({dist[it.second][stop+1],it.second,stop+1});
                }
            }
        }
        int min1=INT_MAX;
        for(int i=0;i<dist[dst].size();i++){
            min1=min(min1,dist[dst][i]);
        }
        if(min1==INT_MAX) return -1;
        return min1;
    }
};