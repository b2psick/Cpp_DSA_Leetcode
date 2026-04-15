class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            pq.push(nums[i]);
        }
        ans.push_back(pq.top());
        for(int i=k;i<nums.size();i++){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0) mp.erase(nums[i-k]);
            mp[nums[i]]++;
            pq.push(nums[i]);
            while(mp.find(pq.top())==mp.end()) pq.pop();
            ans.push_back(pq.top());
        }
        return ans;
    }
};