class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for(auto it : reservedSeats) {
            if(mp[it[0]].find(1) == mp[it[0]].end()) mp[it[0]].insert(1);
            if(mp[it[0]].find(10) == mp[it[0]].end()) mp[it[0]].insert(10);
            mp[it[0]].insert(it[1]);
        }

        int ans = 0;

        for(auto it : mp) {
            int prev = 1;
            bool over = false;
            for(auto element : it.second) {
                if(element == 6 && prev == 1) ans++;
                if(element == 7 && prev == 1) ans++;
                if(element == 8 && prev <= 3) ans++;
                if(element == 10 && prev <= 5) {
                    if(element == 10 && prev == 1) ans+=2;
                    else ans++;
                }
                if(element == 9 && prev <= 3) ans++;
                prev = element;
            }
        }
        ans += (n - mp.size()) * 2;
        return ans;
    }
};