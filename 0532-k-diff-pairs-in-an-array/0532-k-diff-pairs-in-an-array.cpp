class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        unordered_set<int> set;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]+k)!=mp.end()){
                ans++;
                set.insert(nums[i]);
            }
            if(mp.find(nums[i]-k)!=mp.end()){
                ans++;
                set.insert(nums[i]-k);
            }
            mp[nums[i]]++;
        }
        return set.size();
    }
};