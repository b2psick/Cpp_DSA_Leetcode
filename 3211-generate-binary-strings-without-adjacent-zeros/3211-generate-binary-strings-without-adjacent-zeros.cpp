class Solution {
public:
    void ok(int n,string p,vector<string>& ans){
        if(p.length()==n){
            ans.push_back(p);
            return;
        }
        if(p.length()==0){
            ok(n,p+'0',ans);
            ok(n,p+'1',ans);
        }else{
            if(p.back()=='0'){
                ok(n,p+'1',ans);
            }else{
                ok(n,p+'0',ans);
                ok(n,p+'1',ans);
            }
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        ok(n,"",ans);
        return ans;
    }
};