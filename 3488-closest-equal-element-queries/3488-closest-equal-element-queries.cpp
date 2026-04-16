class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans(queries.size(),INT_MAX);
        for(int i=0;i<queries.size();i++){
            int st=0;
            int ed=mp[nums[queries[i]]].size()-1;
            int mid=0;
            int size=mp[nums[queries[i]]].size()-1;
            if(mp[nums[queries[i]]].size()==1){
                ans[i]=-1;
                continue;
            }
            while(st<=ed){
                mid=st+(ed-st)/2;
                if(mp[nums[queries[i]]][mid]==queries[i]){
                    break;
                }
                else if(mp[nums[queries[i]]][mid]>queries[i]){
                    ed=mid-1;
                }else st=mid+1;
            }
            if(mid==0){
                ans[i]=min({ans[i],mp[nums[queries[i]]][1]-mp[nums[queries[i]]][0],(int)nums.size()-mp[nums[queries[i]]][size]+mp[nums[queries[i]]][0]});
            }else if(mid==size){
                ans[i]=min({ans[i],mp[nums[queries[i]]][mid]-mp[nums[queries[i]]][mid-1],(int)nums.size()-mp[nums[queries[i]]][mid]+mp[nums[queries[i]]][0]});
            }else{
                ans[i]=min({ans[i],mp[nums[queries[i]]][mid]-mp[nums[queries[i]]][mid-1],mp[nums[queries[i]]][mid+1]-mp[nums[queries[i]]][mid]});
            }
        }
        return ans;
    }
};