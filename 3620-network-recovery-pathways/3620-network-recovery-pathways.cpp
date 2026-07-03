class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int st=INT_MAX;
        int ed=k;
        vector<vector<pair<int,int>>> ok(online.size());
        for(auto it:edges){
            ok[it[0]].push_back({it[2],it[1]});
            st=min(st,it[2]);
            ed=max(ed,it[2]);
        }
        if(!online[0]) return -1;
        int ans=-1;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            vector<long long> dis(online.size(),LLONG_MAX);
            dis[0]=0;
            priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
            pq.push({0,0});
            bool h=false;
            while(!pq.empty()){
                int a=pq.top().second;
                long long c=pq.top().first;
                pq.pop();
                if(c!=dis[a]) continue;
                if(a==online.size()-1){
                    h=true;
                    break;
                }
                for(auto it:ok[a]){
                    if(online[it.second]&&it.first>=mid&&it.first+c<=k&&it.first+c<dis[it.second]){
                        dis[it.second]=it.first+c;
                        pq.push({c+it.first,it.second});
                    }
                }
            }
            if(h){
                ans=max(ans,mid);
                st=mid+1;
            }else ed=mid-1;
        }
        return ans;
    }
};