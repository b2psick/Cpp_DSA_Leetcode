class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<pair<int,int>> row(grid.size());
        vector<pair<int,int>> col(grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    row[i].first++;
                    col[j].first++;
                }else{
                    row[i].second++;
                    col[j].second++;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<grid.size();i++){
            vector<int> ok;
            for(int j=0;j<grid[0].size();j++){
                ok.push_back(row[i].second+col[j].second-row[i].first-col[j].first);
            }
            ans.push_back(ok);
        }
        return ans;
    }
};