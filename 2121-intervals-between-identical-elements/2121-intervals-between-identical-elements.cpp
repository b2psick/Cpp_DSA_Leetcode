class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        unordered_map<int,long long> mp;
        unordered_map<int,long long> mp1;
        vector<long long> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=i;
            mp1[nums[i]]++;
        }
        unordered_map<int,long long> mp2;
        unordered_map<int,long long> mp3;
        for(int i=0;i<nums.size();i++){
            long long sum=0;
            sum+=abs(mp2[nums[i]]-i*mp3[nums[i]]);
            mp2[nums[i]]+=i;
            mp3[nums[i]]++;
            sum+=abs((mp[nums[i]]-mp2[nums[i]])-i*(mp1[nums[i]]-mp3[nums[i]]));
            ans.push_back(sum);
        }
        return ans;
    }
};