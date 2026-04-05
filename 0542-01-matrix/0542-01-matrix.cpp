class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<int> q;
        vector<vector<int>> ok(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push(i*mat[0].size()+j);
                }
            }
        }
        int a=0;
        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;k++){
                int i=q.front()/mat[0].size();
                int j=q.front()%mat[0].size();
                mat[i][j]=a;
                q.pop();
                if(i>0&&mat[i-1][j]==1&&!ok[i-1][j]){
                    ok[i-1][j]=1;
                    q.push((i-1)*mat[0].size()+j);
                }
                if(j>0&&mat[i][j-1]==1&&!ok[i][j-1]){
                    ok[i][j-1]=1;
                    q.push(i*mat[0].size()+j-1);
                }
                if(i<mat.size()-1&&mat[i+1][j]==1&&!ok[i+1][j]){
                    ok[i+1][j]=1;
                    q.push((i+1)*mat[0].size()+j);
                }
                if(j<mat[0].size()-1&&mat[i][j+1]==1&&!ok[i][j+1]){
                    ok[i][j+1]=1;
                    q.push(i*mat[0].size()+j+1);
                }
            }
            a++;
        }
        return mat;
    }
};