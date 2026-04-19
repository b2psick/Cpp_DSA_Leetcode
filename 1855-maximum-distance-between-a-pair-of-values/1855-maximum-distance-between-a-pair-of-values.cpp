class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=nums1.size()-1;
        int j=nums2.size()-1;
        int ans=INT_MIN;
        while(i>=j) i--;
        while(i>=0&&j>=0){
            if(i==j) i--;
            if(i<0) break;
            if(nums2[j]<nums1[i]){
                j--;
            }else{
                ans=max(ans,j-i);
                i--;
            }
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};