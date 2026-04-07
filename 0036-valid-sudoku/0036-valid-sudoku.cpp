class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> set;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                string a="r"+to_string(i)+board[i][j];
                string b="c"+to_string(j)+board[i][j];
                string c="b"+to_string(i/3)+to_string(j/3)+board[i][j];
                if(set.find(a)!=set.end()||set.find(b)!=set.end()||set.find(c)!=set.end()) return false;
                set.insert(a);
                set.insert(b);
                set.insert(c);
            }
        }
        return true;
    }
};