class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count=0;
        int l=0;
        int r=0;
        for(auto it:moves){
            if(it=='L') l++;
            else if(it=='R') r++;
            else count++;
        }
        return abs(l-r)+count;
    }
};