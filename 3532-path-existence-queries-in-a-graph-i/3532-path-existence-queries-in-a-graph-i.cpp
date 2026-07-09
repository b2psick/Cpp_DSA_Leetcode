class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // vector<vector<int>> ok(n);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(abs(nums[i]-nums[j])<=maxDiff){
        //             ok[i].push_back(j);
        //             ok[j].push_back(i);
        //         }
        //     }
        // }
        // vector<int> mp(n);
        // int a=0;
        // vector<int> vis(n);
        // queue<int> q;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         a++;
        //         q.push(i);
        //     }
        //     while(!q.empty()){
        //         int g=q.front();
        //         mp[g]=a;
        //         q.pop();
        //         for(auto it:ok[g]){
        //             if(!vis[it]){
        //                 q.push(it);
        //                 vis[it]=1;
        //             }
        //         }
        //     }
        // }
        // vector<bool> ans;
        // for(auto it:queries){
        //     if(mp[it[0]]==mp[it[1]]) ans.push_back(true);
        //     else ans.push_back(false);
        // }
        // return ans;
        int a=0;
        vector<int> mp(n);
        mp[0]=0;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff){
                mp[i]=a;
            }else{
                a++;
                mp[i]=a;
            }
        }
        vector<bool> ans;
        for(auto it:queries){
            if(mp[it[0]]==mp[it[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};