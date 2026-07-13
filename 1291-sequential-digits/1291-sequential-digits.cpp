class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string p="123456789";
        string a="";
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            a+=p[i];
            int h=stoi(a);
            while(h>high){
                a.erase(0,1);
                h=stoi(a);
            }
            string k=a;
            while(h>=low&&h<=high){
                ans.push_back(h);
                a.erase(0,1);
                h=stoi(a);
            }
            a=k;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};