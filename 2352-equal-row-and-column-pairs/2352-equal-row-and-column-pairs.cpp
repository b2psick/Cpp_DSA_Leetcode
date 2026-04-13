class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mp;
        unordered_map<string,int> mp1;
        for(auto it:grid){
            string a="";
            for(auto i:it){
                a+=to_string(i)+'.';
            }
            mp[a]++;
        }
        for(int i=0;i<grid[0].size();i++){
            string ok="";
            for(int j=0;j<grid.size();j++){
                ok+=to_string(grid[j][i])+'.';
            }
            mp1[ok]++;
        }
        int ans=0;
        for(auto it:mp){
            ans+=it.second*mp1[it.first];
        }
        return ans;
    }
};