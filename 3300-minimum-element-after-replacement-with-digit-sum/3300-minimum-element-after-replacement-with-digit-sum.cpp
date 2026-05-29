class Solution {
public:
    int minElement(vector<int>& nums) {
        int min1=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int ok=0;
            while(nums[i]!=0){
                ok+=nums[i]%10;
                nums[i]/=10;
            }
            min1=min(min1,ok);
        }
        return min1;
    }
};