class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int ans1=0;
        for(int i=0;i<A.size();i++){
            mp1[A[i]]++;
            if(mp2.find(A[i])!=mp2.end()) ans1++;
            mp2[B[i]]++;
            if(mp1.find(B[i])!=mp1.end()) ans1++;
            ans.push_back(ans1);
        }
        return ans;
    }
};