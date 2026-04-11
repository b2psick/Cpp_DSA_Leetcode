class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto it:mp){
            if(it.second.size()>=3){
                vector<int> ok;
                for(int i=0;i<it.second.size();i++){
                    ok.push_back(it.second[i]);
                }
                for(int i=2;i<ok.size();i++){
                    ans=min(ans,abs(ok[i-2]-ok[i-1])+abs(ok[i-1]-ok[i])+abs(ok[i]-ok[i-2]));
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};