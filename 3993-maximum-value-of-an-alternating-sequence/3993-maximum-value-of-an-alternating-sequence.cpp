class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        int a=n/2;
        long long ans=0;
        int b=max(0,(n-2)/2);
        ans=(long long)a*(long long)m-(long long)b+(long long)s;
        return ans;
    }
};