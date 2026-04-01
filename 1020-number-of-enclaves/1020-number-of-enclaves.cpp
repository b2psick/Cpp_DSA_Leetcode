class Solution {
public:
    bool a;
    int ok(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& p){
        p[i][j]=1;
        if(i==0||i==grid.size()-1||j==0||j==grid[0].size()-1){
            a=true;
            // return 0;
        }
        int sum=1;
        if(i>0&&grid[i-1][j]==1&&!p[i-1][j]){
            sum+=ok(grid,i-1,j,p); 
        }
        if(i<grid.size()-1&&grid[i+1][j]==1&&!p[i+1][j]){
            sum+=ok(grid,i+1,j,p);
        }
        if(j>0&&grid[i][j-1]==1&&!p[i][j-1]){
            sum+=ok(grid,i,j-1,p);
        }
        if(j<grid[0].size()-1&&grid[i][j+1]==1&&!p[i][j+1]){
            sum+=ok(grid,i,j+1,p);
        }
        return sum;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>> p(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(p[i][j]==0&&grid[i][j]==1){
                    a=false;
                    int b=ok(grid,i,j,p);
                    if(!a) ans+=b;
                }
            }
        }
        return ans;
    }
};