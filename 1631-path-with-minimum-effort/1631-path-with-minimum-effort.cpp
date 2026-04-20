class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> ok(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<pair<int,int>> dir({
            {1,0},{-1,0},{0,1},{0,-1}
        });
        if(heights.size()==1&&heights[0].size()==1) return 0;
        while(!pq.empty()){
            int size=pq.size();
            for(int k=0;k<size;k++){
                int i=pq.top().second/heights[0].size();
                int j=pq.top().second%heights[0].size();
                int max1=pq.top().first;
                pq.pop();
                for(auto it:dir){
                    int ni=i+it.first;
                    int nj=j+it.second;
                    if(ni<0||nj<0||ni>=heights.size()||nj>=heights[0].size()){
                        continue;
                    }
                    int abs1=abs(heights[i][j]-heights[ni][nj]);
                    if(max(max1,abs1)<ok[ni][nj]){
                        ok[ni][nj]=max(max1,abs1);
                        pq.push({ok[ni][nj],ni*heights[0].size()+nj});
                    }
                }
            }
        }
        return ok[heights.size()-1][heights[0].size()-1];
    }
};