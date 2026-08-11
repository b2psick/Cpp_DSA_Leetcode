class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prev = nums[0] - 1;
        unordered_set<int> set;
        int sum = 0;
        bool is = true;
        for(auto it : nums) {
            if(it == prev + 1 && is) sum += it;
            else is = false;
            set.insert(it);
            prev = it;
        }
        while(set.find(sum) != set.end()) {
            sum++;
        }
        return sum;
    }
};