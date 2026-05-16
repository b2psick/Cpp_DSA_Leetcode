class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0;
        int ed=nums.size()-1;
        int min1=INT_MAX;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            min1=min(min1,nums[mid]);
            if(nums[mid]>nums[ed]){
                st=mid+1;
            }else if(nums[mid]<nums[ed]){
                ed=mid-1;
            }else ed--;
        }
        return min1;
    }
};