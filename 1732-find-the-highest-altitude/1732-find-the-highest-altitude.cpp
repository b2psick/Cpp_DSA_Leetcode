class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max1=INT_MIN;
        int sum=0;
        for(auto it:gain){
            sum+=it;
            max1=max(max1,sum);
        }
        if(max1<0) return 0;
        return max1;
    }
};