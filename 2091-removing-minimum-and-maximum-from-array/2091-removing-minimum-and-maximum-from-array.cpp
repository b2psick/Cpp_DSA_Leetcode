class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min1=INT_MAX;
        int max1=INT_MIN;
        int min1i=0;
        int max1i=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min1){
                min1=nums[i];
                min1i=i;
            }
            if(nums[i]>max1){
                max1=nums[i];
                max1i=i;
            }
        }
        int ok=min(min1i,max1i);
        int ok1=max(min1i,max1i);
        int n=nums.size();
        int ans=min({ok+n-ok1+1,ok1+1,n-ok});
        return ans;
    }
};