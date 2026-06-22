class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto it:text) mp[it]++;
        mp['l']/=2;
        mp['o']/=2;
        int ans=INT_MAX;
        ans=min({mp['b'],mp['a'],mp['l'],mp['o'],mp['n']});
        return ans;
    }
};