class Solution {
public:
    bool ok(vector<int>& arr,int i,vector<int>& vis){
        if(arr[i]==0) return true;
        if(vis[i]) return false;
        vis[i]=true;
        if(i+arr[i]<arr.size()){
            if(ok(arr,i+arr[i],vis)) return true;
        }
        if(i-arr[i]>=0){
            if(ok(arr,i-arr[i],vis)) return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size());
        return ok(arr,start,vis);
    }
};