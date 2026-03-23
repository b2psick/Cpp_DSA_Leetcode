class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        vector<vector<pair<long long,long long>>> arr(grid.size(),vector<pair<long long,long long>>(grid[0].size()));
        arr[0][0].first=grid[0][0];
        arr[0][0].second=grid[0][0];
        for(int i=1;i<grid.size();i++){
            arr[i][0].first=arr[i-1][0].first*grid[i][0];
            arr[i][0].second=arr[i-1][0].second*grid[i][0];
        }
        for(int i=1;i<grid[0].size();i++){
            arr[0][i].first=arr[0][i-1].first*grid[0][i];
            arr[0][i].second=arr[0][i-1].second*grid[0][i];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                long long lf=arr[i-1][j].first;
                long long ls=arr[i-1][j].second;
                long long tf=arr[i][j-1].first;
                long long ts=arr[i][j-1].second;
                int a=grid[i][j];
                arr[i][j].first=max({a*lf,a*ls,a*tf,a*ts});
                arr[i][j].second=min({a*lf,a*ls,a*tf,a*ts});
            }
        }
        if(arr[grid.size()-1][grid[0].size()-1].first<0) return -1;
        return arr[grid.size()-1][grid[0].size()-1].first%1000000007;
    }
};