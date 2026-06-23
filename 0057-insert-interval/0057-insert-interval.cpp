class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        interval.push_back(newInterval);
        vector<vector<int>> ans;
        sort(interval.begin(),interval.end());
        ans.push_back(interval[0]);
        for(int i=1;i<interval.size();i++){
            if(interval[i][0]<=ans.back()[1]){
                ans.back()[1]=max(interval[i][1],ans.back()[1]);
            }else{
                ans.push_back(interval[i]);
            }
        }
        return ans;
    }
};