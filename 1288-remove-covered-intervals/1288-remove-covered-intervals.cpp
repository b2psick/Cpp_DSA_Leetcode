class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<vector<int>> ok;
        ok.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ok.back()[0]<=intervals[i][0]&&ok.back()[1]>=intervals[i][1]){
                continue;
            }else{
                ok.push_back(intervals[i]);
            }
        }
        return ok.size();
    }
};