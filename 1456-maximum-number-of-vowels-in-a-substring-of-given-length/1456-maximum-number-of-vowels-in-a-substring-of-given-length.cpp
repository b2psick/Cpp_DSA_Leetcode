class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=-1;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count++;
            }
            if(i>=k-1){
                ans=max(ans,count);
                if(ans==k) return k;
                if(s[i-k+1]=='a'||s[i-k+1]=='e'||s[i-k+1]=='i'||s[i-k+1]=='o'||s[i-k+1]=='u'){
                    count--;
                }
            }
        }
        return ans;
    }
};