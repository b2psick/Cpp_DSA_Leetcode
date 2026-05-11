class Solution {
public:
    string ans="";
    bool ok(string pattern,string p,int j,vector<int>& vis){
        if(p.size()==pattern.size()+1){
            ans=p;
            return true;
        }
        for(int i=1;i<=9;i++){
            if(j==0){
                vis[i-1]=1;
                if(ok(pattern,p+to_string(i),j+1,vis)) return true;
                vis[i-1]=0;
            }else{
                if(pattern[j-1]=='I'&&i>p.back()-'0'&&!vis[i-1]){
                    vis[i-1]=1;
                    if(ok(pattern,p+to_string(i),j+1,vis)) return true;
                    vis[i-1]=0;
                }else if(pattern[j-1]=='D'&&i<p.back()-'0'&&!vis[i-1]){
                    vis[i-1]=1;
                    if(ok(pattern,p+to_string(i),j+1,vis)) return true;
                    vis[i-1]=0;
                }
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        vector<int> vis(9);
        ok(pattern,"",0,vis);
        return ans;
    }
};