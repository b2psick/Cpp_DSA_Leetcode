class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=x;
        int m=x+k-1;
        while(n<m){
            for(int j=y;j<y+k;j++){
                swap(grid[n][j],grid[m][j]);
            }
            n++;
            m--;
        }
        return grid;
    }
};