class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddMin = INT_MAX;
        for(auto it : nums1) {
            if(it % 2 != 0) oddMin = min(oddMin, it);;
        }
        int even = 0;
        int odd = 0;
        for(auto it : nums1) {
            if(it % 2 == 0) {
                even++;
                if(oddMin != INT_MAX && oddMin < it) odd++;
            }

            if(it % 2 != 0) {
                odd++;
                if(oddMin != INT_MAX && oddMin < it) even++;
            }
        }
        return even == nums1.size() || odd == nums1.size();
    }
};