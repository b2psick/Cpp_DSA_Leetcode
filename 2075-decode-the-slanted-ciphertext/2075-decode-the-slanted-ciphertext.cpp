class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows==1) return encodedText;
        vector<vector<char>> ok(rows,vector<char>(encodedText.length()/rows));
        int k=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<encodedText.length()/rows;j++){
                ok[i][j]=encodedText[k];
                k++;
            }
        }
        string ans="";
        for(int i=0;i<encodedText.length()/rows;i++){
            for(int j=0;j<rows;j++){
                if(j+i>=encodedText.length()/rows) break;
                ans+=ok[j][j+i];
            }
        }
        while(!ans.empty()&&ans.back()==' ') ans.pop_back();
        return ans;
    }
};