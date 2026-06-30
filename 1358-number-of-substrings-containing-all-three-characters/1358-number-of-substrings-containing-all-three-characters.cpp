class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int count=0;
        int left=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            while(left<i){
                if(mp[s[left]]>1){
                    mp[s[left]]--;
                    left++;
                    count++;
                }else{
                    break;
                }
            }
            if(mp['a']>=1&&mp['b']>=1&&mp['c']>=1){
                ans+=1+count;
            }
        }
        return ans;
    }
};