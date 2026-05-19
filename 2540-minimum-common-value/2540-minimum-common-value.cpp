class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int a=0;
        int b=0;
        while(a<nums1.size()&&b<nums2.size()){
            if(nums1[a]>nums2[b]){
                b++;
            }else if(nums1[a]<nums2[b]){
                a++;
            }else return nums1[a];
        }
        return -1;
    }
};