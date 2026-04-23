class Solution {
public:
    int dfs(vector<vector<pair<long long,int>>>& ok,vector<long long>& dist,int node,int dst,vector<int>& memo){
        if(memo[node]!=-1){
            return memo[node];
        }
        int sum=0;
        for(auto it:ok[node]){
            if(dist[node]+it.first==dist[it.second]){
                if(it.second==dst) sum++;
                else sum+=dfs(ok,dist,it.second,dst,memo);
                sum=sum%1000000007;
            }
        }
        memo[node]=sum;
        return sum;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<vector<pair<long long,int>>> ok(n);
        if(n==1) return 1;
        for(int i=0;i<roads.size();i++){
            ok[roads[i][0]].push_back({roads[i][2],roads[i][1]});
            ok[roads[i][1]].push_back({roads[i][2],roads[i][0]});
        }
        vector<long long> dist(n,LLONG_MAX);
        long long ans=0;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            long long wt=pq.top().first;
            pq.pop();
            if(wt>dist[node]) continue;
            for(auto it:ok[node]){
                if(wt+it.first<dist[it.second]){
                    dist[it.second]=wt+it.first;
                    pq.push({dist[it.second],it.second});
                }
            }
        }
        vector<int> vis(n);
        vector<int> memo(n,-1);
        ans=dfs(ok,dist,0,n-1,memo);
        return ans%1000000007;
    }
};