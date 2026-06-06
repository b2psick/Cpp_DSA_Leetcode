class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int sum=0;
        for(auto it:nums) sum+=it;
        int sum1=0;
        for(auto it:nums){
            sum-=it;
            ans.push_back(abs(sum-sum1));
            sum1+=it;
        }
        return ans;
    }
};