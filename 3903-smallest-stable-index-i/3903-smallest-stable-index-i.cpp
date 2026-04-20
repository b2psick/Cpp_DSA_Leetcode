class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int max1=INT_MIN;
        int min1=INT_MAX;
        vector<int> ok(nums.size(),INT_MAX);
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1) ok[i]=nums[i];
            else ok[i]=min(ok[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            max1=max(max1,nums[i]);
            if(max1-ok[i]<=k) return i;
        }
        return -1;
    }
};