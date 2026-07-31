class Solution {
public:
    int minimumPushes(string word) {
        int count = 1;
        int ans = 0;
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        for(auto it : word) {
            mp[it]++;
        }
        for(auto it : mp) {
            pq.push(it.second);
        }
        while(!pq.empty()) {
            int a = 1;
            if(count <= 8) {
                a = 1;
            }else if(count <= 16) {
                a = 2;
            }else if(count <= 24) {
                a = 3;
            }else {
                a = 4;
            }
            ans += pq.top() * a;
            pq.pop();
            count++;
        }
        return ans;
    }
};