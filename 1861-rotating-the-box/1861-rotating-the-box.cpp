class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        for(int i=0;i<boxGrid.size();i++){
            int count=0;
            for(int j=0;j<boxGrid[0].size();j++){
                if(boxGrid[i][j]=='#') count++;
                if(boxGrid[i][j]=='*'){
                    for(int k=j-1;k>=0;k--){
                        if(boxGrid[i][k]=='*'){
                            break;
                        }else if(count>0){
                            boxGrid[i][k]='#';
                            count--;
                        }else{
                            boxGrid[i][k]='.';
                        }
                    }
                }
                else if(j==boxGrid[0].size()-1){
                    for(int k=j;k>=0;k--){
                        if(boxGrid[i][k]=='*'){
                            break;
                        }else if(count>0){
                            boxGrid[i][k]='#';
                            count--;
                        }else{
                            boxGrid[i][k]='.';
                        }
                    }
                }
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