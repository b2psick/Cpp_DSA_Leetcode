class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int a=-1;
        for(int i=0;i<interval.size();i++){
            if(interval[i][0]>newInterval[0]){
                a=i;
                break;
            }
        }
        if(a==-1) a=interval.size();
        interval.insert(interval.begin()+a,newInterval);
        for(auto it:interval){
            for(auto it1:it){
                cout<<it1<<" ";
            }
            cout<<endl;
        }
        vector<vector<int>> ans;
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