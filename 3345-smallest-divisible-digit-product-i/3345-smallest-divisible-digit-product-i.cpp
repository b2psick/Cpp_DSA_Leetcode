class Solution {
public:
    int smallestNumber(int n, int t) {
        int count = 0;
        while(true) {
            int product = 1;
            int curr = n;
            while(curr != 0) {
                product = product * (curr % 10);
                curr /= 10;
            }
            if(product % t == 0) return n;
            count++;
            if(count == 11) break;
            n++;
        }
        return -1;
    }
};