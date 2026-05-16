class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0;
        int ed=nums.size()-1;
        int min1=INT_MAX;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(nums[mid]<min1){
                min1=nums[mid];
            }
            while(st<ed&&nums[st]==nums[ed]){
                if(nums[st]<min1) min1=nums[st];
                st++;
                ed--;
            }
            if(nums[mid]>nums[ed]){
                st=mid+1;
            }else ed=mid-1;
        }
        return min1;
    }
};