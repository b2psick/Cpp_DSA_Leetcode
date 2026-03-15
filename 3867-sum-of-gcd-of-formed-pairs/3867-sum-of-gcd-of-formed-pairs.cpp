class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int max1=nums[0];
        vector<int> ok;
        for(int i=0;i<nums.size();i++){
            max1=max(nums[i],max1);
            ok.push_back(gcd(nums[i],max1));
        }
        sort(ok.begin(),ok.end());
        int st=0;
        int ed=ok.size()-1;
        long long ans=0;
        while(st<ed){
            ans+=gcd(ok[st],ok[ed]);
            st++;
            ed--;
        }
        return ans;
    }
};