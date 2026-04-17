class Solution {
public:
    int rev(int num){
        int ans=0;
        while(num!=0){
            ans=ans*10+num%10;
            num/=10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[rev(nums[i])]=i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};