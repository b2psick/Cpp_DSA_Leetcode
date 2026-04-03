class Solution {
public:
    void ok(vector<vector<char>>& board,int i,int j,vector<vector<int>>& p){
        if(i>=board.size()||i<0||j<0||j>=board[0].size()||p[i][j]||board[i][j]=='X') return;
        board[i][j]='a';
        p[i][j]=1;
        ok(board,i+1,j,p);
        ok(board,i-1,j,p);
        ok(board,i,j+1,p);
        ok(board,i,j-1,p);
    }
    void solve(vector<vector<char>>& board) {
        //we can solve this ques using 2 dfs by first checking if the components is touching any border or not if not then it can be surrounded and then we can just make the whole component 'X'
        //the optimal thing is we make the border '0' component something else and then just traverse the graph and make the '0' to 'X'
        vector<vector<int>> p(board.size(),vector<int>(board[0].size()));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0||j==0||i==board.size()-1||j==board[0].size()-1)&&!p[i][j]){
                    ok(board,i,j,p);
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='a') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};