class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long p = 1000000000000000;
        while(p > 999) {
            if(n >= p) {
                ans += n - p + 1;
            }
            p /= 1000;
        }
        return ans;
    }
};