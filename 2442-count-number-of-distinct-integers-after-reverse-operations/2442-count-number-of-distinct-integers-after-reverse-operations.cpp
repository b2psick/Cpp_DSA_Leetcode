class Solution {
public:
    int rev(int num){
        int p=0;
        while(num!=0){
            p=p*10+num%10;
            num=num/10;
        }
        return p;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> set;
        for(auto it:nums){
            set.insert(it);
            set.insert(rev(it));
        }
        return set.size();
    }
};