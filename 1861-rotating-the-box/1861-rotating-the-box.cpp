class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        for(int i=0;i<boxGrid.size();i++){
            int p=-1;
            for(int j=boxGrid[0].size()-1;j>=0;j--){
                if(boxGrid[i][j]=='#'){
                    if(p!=-1){
                        boxGrid[i][j]='.';
                        boxGrid[i][p]='#';
                        p--;
                    }
                }else if(boxGrid[i][j]=='*') p=-1;
                else if(p==-1) p=j;
            }
        }
        vector<vector<char>> ans(boxGrid[0].size(),vector<char>(boxGrid.size()));
        for(int i=0;i<boxGrid.size();i++){
            for(int j=0;j<boxGrid[0].size();j++){
                ans[j][boxGrid.size()-i-1]=boxGrid[i][j];
            }
        }
        return ans;
    }
};