class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int left=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(left<i){
                if(sum-nums[left]<target) break;
                sum=sum-nums[left];
                left++;
            }
            if(sum>=target) ans=min(ans,i-left+1);
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};