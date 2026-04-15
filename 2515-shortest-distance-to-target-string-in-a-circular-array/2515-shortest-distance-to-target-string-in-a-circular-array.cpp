class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int i=startIndex;
        int j=0;
        int ans=INT_MAX;
        while(j<words.size()){
            if(words[(i+words.size())%words.size()]==target){
                ans=min(ans,j);
            }
            i--;
            j++;
        }
        j=0;
        i=startIndex;
        while(j<words.size()){
            if(words[(i)%words.size()]==target){
                ans=min(ans,j);
            }
            i++;
            j++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};