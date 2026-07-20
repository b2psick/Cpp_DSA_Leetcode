class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> ans;
        int a=0;
        k=k%(grid.size()*grid[0].size());
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                if(a==k) break;
                a++;
                ans.push_back(grid[i][j]);
            }
            if(a==k) break;
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(a==grid.size()*grid[0].size()) break;
                a++;
                ans.push_back(grid[i][j]);
            }
            if(a==grid.size()*grid[0].size()) break;
        }
        a=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=ans[a];
                a++;
            }
        }
        return grid;
    }
};