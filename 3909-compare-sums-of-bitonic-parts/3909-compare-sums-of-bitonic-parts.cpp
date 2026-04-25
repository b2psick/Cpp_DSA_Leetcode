class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long prev=nums[0];
        long long sum1=nums[0];
        long long sum2=0;
        bool ok=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<prev&&!ok){
                ok=true;
                sum2+=prev;
            }
            if(ok){
                sum2+=nums[i];
            }else{
                sum1+=nums[i];
            }
            prev=nums[i];
        }
        if(sum1>sum2) return 0;
        else if(sum1<sum2) return 1;
        else return -1;
    }
};