class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        for(auto it:grid){
            for(auto it1:it) sum+=it1;
        }
        if(sum%2!=0) return false;
        long long sum1=0;
        long long sum2=0;
        for(auto it:grid){
            for(auto it1:it) sum1+=it1;
            if(sum1==sum-sum1) return true;
        }
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                sum2+=grid[j][i];
            }
            if(sum2==sum-sum2) return true;
        }
        return false;
    }
};