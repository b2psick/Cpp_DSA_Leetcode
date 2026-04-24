class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,long long> mp;
        unordered_map<int,long long> mp1;
        vector<long long> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=i;
            mp1[nums[i]]++;
        }
        unordered_map<int,long long> mp2;
        unordered_map<int,long long> mp3;
        //here is also a thing that why we are calculating the left right side seperately because the index smaller than current would give something in abs but if we combine left and right they would not because it would be right-left and thats why we calculate both the left and right seperately but if there was no abs use then we would have combined them
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