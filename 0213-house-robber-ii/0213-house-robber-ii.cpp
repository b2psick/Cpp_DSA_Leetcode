class Solution {
public:
    int robber(vector<int>& nums, int st, int ed) {
        int a=0;
        int b=0;
        int c=0;
        for(int i=st;i<=ed;i++){
            c = max(b, nums[i] + a);
            a = b;
            b = c;
        }
        return c;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(robber(nums, 0, nums.size() - 2), robber(nums, 1, nums.size() - 1));
    }
};