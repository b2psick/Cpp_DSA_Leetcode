class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> col(mat[0].size());
        vector<int> row(mat.size());
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    col[j]++;
                    row[i]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(row[i]==1&&col[j]==1&&mat[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};