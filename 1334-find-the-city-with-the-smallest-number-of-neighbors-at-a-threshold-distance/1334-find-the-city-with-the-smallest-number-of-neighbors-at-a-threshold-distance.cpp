class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> ok(n,vector<int>(n,-1));
        for(int i=0;i<edges.size();i++){
            ok[edges[i][0]][edges[i][1]]=edges[i][2];
            ok[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) ok[i][j]=0;
                if(ok[i][j]==-1) ok[i][j]=INT_MAX;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(ok[i][k]==INT_MAX||ok[k][j]==INT_MAX) continue;
                    ok[i][j]=min(ok[i][j],ok[i][k]+ok[k][j]);
                }
            }
        }
        int ans=-1;
        int min1=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(ok[i][j]<=distanceThreshold) count++;
            }
            if(count<min1){
                min1=count;
                ans=i;
            }else if(count==min1) ans=i;
        }
        return ans;
    }
};