class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        int ans=s.length();
        for(auto it:mp){
            if(it.second%2==0){
                ans-=it.second-2;
            }else{
                ans-=it.second-1;
            }
        }
        return ans;
    }
};