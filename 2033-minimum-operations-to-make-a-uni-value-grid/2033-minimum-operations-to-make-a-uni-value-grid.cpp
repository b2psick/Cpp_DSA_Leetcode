class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ok;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ok.push_back(grid[i][j]);
            }
        }
        sort(ok.begin(),ok.end());
        int med=ok[ok.size()/2];
        int ans=0;
        for(int i=0;i<ok.size();i++){
            if(abs(ok[i]-med)%x!=0) return -1;
            ans+=abs(ok[i]-med)/x;
        }
        return ans;
    }
};