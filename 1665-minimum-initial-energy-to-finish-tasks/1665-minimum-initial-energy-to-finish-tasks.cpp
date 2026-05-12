class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a,vector<int>& b){
            return a[1]-a[0]>b[1]-b[0];
        });
        int ans=0;
        int k=0;
        for(int i=0;i<tasks.size();i++){
            if(k<tasks[i][1]){
                ans+=(tasks[i][1]-k);
                k=tasks[i][1];
            }
            if(k<tasks[i][0]){
                ans+=(tasks[i][0]-k);
                k=tasks[i][0];
            }
            k-=tasks[i][0];
            cout<<tasks[i][0]<<endl;
        }
        return ans;
    }
};