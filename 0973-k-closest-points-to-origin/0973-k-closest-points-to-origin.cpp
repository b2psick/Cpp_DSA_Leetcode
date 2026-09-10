class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto it : points) {
            int curr = it[0] * it[0] + it[1] * it[1];
            pq.push({(int)curr, it});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};