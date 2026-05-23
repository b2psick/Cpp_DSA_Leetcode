class Solution {
public:
    bool check(vector<int>& nums) {
        int p=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                p++;
            }
        }
        if(p>1) return false;
        else if(p>=1&&nums[0]<nums[nums.size()-1]) return false;
        return true;
    }
};