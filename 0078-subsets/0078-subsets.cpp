class Solution {
public:
    // void sub(vector<vector<int>>& ok,vector<int>& ok1,int a,vector<int> p){
    //     ok.push_back(ok1);
    //     for(int i=a;i<p.size();i++){
    //         ok1.push_back(p[i]);
    //         sub(ok,ok1,i+1,p);
    //         ok1.pop_back();
    //     }
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ok;
        // vector<int> ok1;
        // sub(ok,ok1,0,nums);
        // return ok;

        //using bit mani

        vector<vector<int>> ans;
        for(int i = 0; i < (1 << nums.size()); i++) {
            vector<int> curr;
            for(int j = 0; j < nums.size(); j++) {
                if((i >> j) & 1) curr.push_back(nums[j]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};