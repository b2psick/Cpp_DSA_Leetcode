class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> ok(n);
        for(int i=0;i<times.size();i++){
            ok[times[i][0]-1].push_back({times[i][2],times[i][1]-1});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        dist[k-1]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(wt>dist[node]) continue;
            for(auto it:ok[node]){
                if(wt+it.first<dist[it.second]){
                    dist[it.second]=wt+it.first;
                    pq.push({dist[it.second],it.second});
                }
            }
        }
        int max1=INT_MIN;
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX) return -1;
            max1=max(max1,dist[i]);
        }
        return max1;
    }
};