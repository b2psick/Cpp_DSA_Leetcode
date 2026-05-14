class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max1=INT_MIN;
        for(auto it:nums) max1=max(max1,it);
        mp[max1]--;
        if(nums.size()!=max1+1) return false; 
        for(auto it:nums){
            if(it>max1) return false;
            mp[it]++;
            if(mp[it]>1) return false;
        }
        if(mp[max1]!=1) return false;
        return true;
    }
};