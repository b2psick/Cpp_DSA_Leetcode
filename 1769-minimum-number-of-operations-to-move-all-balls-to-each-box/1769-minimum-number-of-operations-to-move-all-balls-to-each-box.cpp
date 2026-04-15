class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length());
        int count=0;
        int ok=0;
        for(int i=0;i<boxes.length();i++){
            ans[i]=ok;
            if(boxes[i]=='1') count++;
            ok+=count;
        }
        count=0;
        ok=0;
        for(int i=boxes.length()-1;i>=0;i--){
            ans[i]+=ok;
            if(boxes[i]=='1') count++;
            ok+=count;
        }
        return ans;
    }
};