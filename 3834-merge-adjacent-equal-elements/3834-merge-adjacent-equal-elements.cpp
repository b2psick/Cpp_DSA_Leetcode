class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        for(long long i=0;i<nums.size();i++){
            st.push(nums[i]);
            while(st.size()>=2){
                long long a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();
                if(a==b) st.push(a+b);
                else{
                    st.push(b);
                    st.push(a);
                    break;
                }
            }
        }
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};