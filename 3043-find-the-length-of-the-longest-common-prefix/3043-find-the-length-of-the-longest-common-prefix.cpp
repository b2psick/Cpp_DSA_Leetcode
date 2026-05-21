class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> set;
        for(int i=0;i<arr1.size();i++){
            string a=to_string(arr1[i]);
            int length=a.length();
            for(int j=0;j<length;j++){
                set.insert(a);
                a.pop_back();
            }
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            string a=to_string(arr2[i]);
            int length=a.length();
            for(int j=0;j<length;j++){
                if(set.find(a)!=set.end()){
                    ans=max(ans,(int)a.length());
                    break;
                }
                a.pop_back();
            }
        }
        return ans;
    }
};