class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int a=1;
        for(auto it:mp){
            for(auto it1:it.second){
                arr[it1]=a;
            }
            a++;
        }
        return arr;
    }
};