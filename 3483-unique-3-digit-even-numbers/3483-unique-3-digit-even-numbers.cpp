class Solution {
public:
    unordered_set<int> set;
    void helper(vector<int>& digits, int curr, vector<int>& marked) {
        if(curr >= 100) {
            if(set.find(curr) != set.end() || curr % 2 != 0) {
                return;
            }
            set.insert(curr);
            return;
        }
        int currAns = 0;
        for(int i = 0; i < digits.size(); i++) {
            if(!marked[i]) {
                marked[i] = 1;
                helper(digits, curr * 10 + digits[i], marked);
                marked[i] = 0;
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        vector<int> marked(digits.size());
        helper(digits, 0, marked);
        return set.size();
    }
};