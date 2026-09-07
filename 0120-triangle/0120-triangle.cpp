class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size() - 1].size());
        int ans = INT_MAX;
        vector<int> prev(triangle[triangle.size() - 1].size());
        for(int i = 0; i < triangle.size(); i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                if(i == 0 && j == 0) {
                    dp[0] = triangle[0][0];
                    continue;
                }
                if(j == 0) {
                    dp[j] = prev[j] + triangle[i][0];
                }else if(j == triangle[i].size() - 1){
                    dp[j] = triangle[i][j] + prev[j - 1];
                }else {
                    dp[j] = triangle[i][j] + min(prev[j], prev[j - 1]);
                }
                if(i == triangle.size() - 1) ans = min(ans, dp[j]);
            }
            prev = dp;
        }
        return ans == INT_MAX ? triangle[0][0] : ans;
    }
};