class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        vector<pair<int,int>> ok1;
        int min1=0;
        int i=-1;
        r.push_back({1,0});
        ok1.push_back({1,0});
        sort(r.begin(),r.end());
        for(auto it:r){
            if(i!=-1){
                min1=min1+it[0]-i;
                ok1.push_back({it[0],min(it[1],min1)});
                min1=min(min1,it[1]);
            }
            i=it[0];
        }
        sort(r.begin(), r.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]>b[0];
        });
        i=-1;
        int a=0;
        min1=r[0][1];
        for(auto it:r){
            if(i!=-1){
                min1=min1+i-it[0];
                ok1[ok1.size()-a-1].second=min(ok1[ok1.size()-a-1].second,min1);
                min1=min(min1,it[1]);
            }
            i=it[0];
            a++;
        }
        int max1=INT_MIN;
        i=-1;
        int h=0;
        for(auto it:ok1){
            if(i!=-1){
                int d=abs(it.first-i);
                int h1=abs(it.second-h);
                max1=max(max1,max(it.second,h)+abs(d-h1)/2);
            }
            i=it.first;
            h=it.second;
        }
        if(max1==INT_MIN) return n-1;
        max1=max(max1,h+n-i);
        return max1;
    }
};