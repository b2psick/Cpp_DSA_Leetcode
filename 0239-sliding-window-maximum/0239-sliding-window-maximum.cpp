class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> ans;
        // unordered_map<int,int> mp;
        // priority_queue<int> pq;
        // for(int i=0;i<k;i++){
        //     mp[nums[i]]++;
        //     pq.push(nums[i]);
        // }
        // ans.push_back(pq.top());
        // for(int i=k;i<nums.size();i++){
        //     mp[nums[i-k]]--;
        //     if(mp[nums[i-k]]==0) mp.erase(nums[i-k]);
        //     mp[nums[i]]++;
        //     pq.push(nums[i]);
        //     while(mp.find(pq.top())==mp.end()) pq.pop();
        //     ans.push_back(pq.top());
        // }
        // return ans;

        //more optimal using monotonic deque 
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty()&&dq.front()==i-k){
                dq.pop_front();
            }
            while(!dq.empty()&&nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};