class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int,int> mp;
        int p=0;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(nums[i]<0){
                p++;
                mp[nums[i]]++;
            }
        }
        int a=0;
        if(p<x) ans.push_back(0);
        else{
            for(auto it:mp){
                a+=it.second;
                if(a>=x){
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        for(int i=k;i<nums.size();i++){
            a=0;
            if(nums[i-k]<0){
                p--;
                mp[nums[i-k]]--;
            }
            if(nums[i]<0){
                p++;
                mp[nums[i]]++;
            }
            if(p<x) ans.push_back(0);
            else{
                for(auto it:mp){
                    a+=it.second;
                    if(a>=x){
                        ans.push_back(it.first);
                        break;
                    }
                }
        }
        }
        return ans;
    }
};