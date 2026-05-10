class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        unordered_map<string,string> mp1;
        unordered_map<string,int> mp2;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                mp1[accounts[i][j]]=accounts[i][0];
                mp2[accounts[i][j]]=0;
                for(int k=j;k<accounts[i].size();k++){
                    if(k!=j){
                        mp[accounts[i][j]].push_back(accounts[i][k]);
                        mp[accounts[i][k]].push_back(accounts[i][j]);
                    }
                }
            }
        }
        queue<string> q;
        for(auto it:mp2){
            if(!mp2[it.first]){
                mp2[it.first]=1;
                q.push(it.first);
                vector<string> ok;
                while(!q.empty()){
                    int size=q.size();
                    for(int i=0;i<size;i++){
                        string a=q.front();
                        ok.push_back(a);
                        q.pop();
                        for(auto it1:mp[a]){
                            if(!mp2[it1]){
                                mp2[it1]=1;
                                q.push(it1);
                            }
                        }
                    }
                }
                sort(ok.begin(),ok.end());
                ok.insert(ok.begin(),mp1[it.first]);
                ans.push_back(ok);
            }
        }
        return ans;
    }
};