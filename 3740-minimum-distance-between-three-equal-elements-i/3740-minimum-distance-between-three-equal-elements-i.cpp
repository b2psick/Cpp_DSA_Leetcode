class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]!=nums[i]) continue;
                for(int k=j+1;k<nums.size();k++){
                    if(nums[k]==nums[j]){
                        ans=min(ans,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};