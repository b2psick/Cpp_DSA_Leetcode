class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
    double slope;

    for(int i = 0; i < points.size(); i++) {

        int currMax = 0;
        unordered_map<double, int> mp;
        int duplicates = 0;

        for(int j = i + 1; j < points.size(); j++) {

            if(points[i] == points[j]) {
                duplicates++;
                continue;
            }

            if(points[j][0] - points[i][0] == 0) {
                slope = INT_MAX;
            } else {
                slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
            }

            if(mp.find(slope) == mp.end()) {
                mp[slope] = 1;
            }

            mp[slope]++;
            currMax = max(currMax, mp[slope]);

        }

        ans = max(ans, currMax + duplicates);
    }

    return max(1, ans);
    }
};