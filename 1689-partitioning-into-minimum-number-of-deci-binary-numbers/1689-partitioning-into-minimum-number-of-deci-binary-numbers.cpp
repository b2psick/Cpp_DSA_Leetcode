class Solution {
public:
    int minPartitions(string n) {
        int max1=INT_MIN;
        for(auto it:n) max1=max(max1,it-'0');
        return max1;
    }
};