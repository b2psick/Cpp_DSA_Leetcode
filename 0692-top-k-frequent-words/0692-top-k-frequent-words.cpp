class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>,vector<pair<string,int>>,function<bool(pair<string,int>, pair<string,int>)>> pq(
        [](pair<string,int> a, pair<string,int> b) {
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second < b.second;
        }
    );
        unordered_map<string,int> mp;
        for(auto it:words) mp[it]++;
        for(auto it:mp) pq.push({it.first,it.second});
        int i=0;
        vector<string> ans;
        while(i<k){
            ans.push_back(pq.top().first);
            i++;
            pq.pop();
        }
        return ans;
    }
};