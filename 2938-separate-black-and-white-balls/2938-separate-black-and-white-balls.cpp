class Solution {
public:
    long long minimumSteps(string s) {
        long long count=0;
        long long ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') count++;
            else ans+=count;
        }
        return ans;
    }
};