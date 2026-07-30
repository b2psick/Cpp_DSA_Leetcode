class Solution {
public:
    int minimumPushes(string word) {
        int size = word.length();
        int ans = 0;
        ans += min(size, 8);
        size -= 8;
        if(size <= 0) return ans;
        ans += min(size*2, 16);
        size -= 8;
        if(size <= 0) return ans;
        ans += min(size*3, 24);
        size -= 8;
        if(size <= 0) return ans;
        ans += min(size*4, 8);
        return ans;
    }
};