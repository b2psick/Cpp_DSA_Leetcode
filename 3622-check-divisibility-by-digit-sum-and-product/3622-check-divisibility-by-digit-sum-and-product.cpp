class Solution {
public:
    bool checkDivisibility(int n) {
        int p = 1;
        int original = n;
        int sum = 0;
        while(n != 0) {
            sum += n % 10;
            p *= n % 10;
            n /=10;
        }
        return original % (sum + p) == 0;
    }
};