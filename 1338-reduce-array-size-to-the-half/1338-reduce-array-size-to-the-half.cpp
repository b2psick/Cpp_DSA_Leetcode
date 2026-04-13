class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>, pair<int,int>)>> pq(
            [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
            }
        );
        unordered_map<int,int> mp;
        for(auto it:arr) mp[it]++;
        for(auto it:mp) pq.push({it.first,it.second});
        int size=arr.size();
        int ans=0;
        while(!pq.empty()){
            ans++;
            size-=pq.top().second;
            cout<<size<<endl;
            if(size<=arr.size()/2) break;
            pq.pop();
        }
        return ans;
    }
};