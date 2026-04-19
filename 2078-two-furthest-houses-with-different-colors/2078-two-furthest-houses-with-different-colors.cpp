class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left=colors[0];
        int right=colors[colors.size()-1];
        int ans=INT_MIN;
        for(int i=0;i<colors.size();i++){
            if(colors[i]!=right){
                ans=max(ans,(int)colors.size()-i-1);
            }
            if(colors[i]!=left){
                ans=max(ans,i);
            }
        }
        return ans;
    }
};