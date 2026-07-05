class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<long long>> dp(board.size(),vector<long long>(board[0].size()));
        dp[0][0]=0;
        bool ok=false;
        for(int i=1;i<board.size();i++){
            if(board[i][0]=='X'){
                ok=true;
            }
            if(!ok){
                dp[i][0]=dp[i-1][0]+(board[i][0]-'0');
            }
        }
        ok=false;
        for(int i=1;i<board[0].size();i++){
            if(board[0][i]=='X'){
                ok=true;
            }
            if(!ok){
                dp[0][i]=dp[0][i-1]+(board[0][i]-'0');
            } 
        }
        for(int i=1;i<board.size();i++){
            for(int j=1;j<board[0].size();j++){
                if(board[i][j]!='X'&&(dp[i-1][j]!=0||dp[i][j-1]!=0||dp[i-1][j-1]!=0)){
                    if(i==board.size()-1&&j==board[0].size()-1){
                        dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})%1000000007;
                    }else{
                        dp[i][j]=((board[i][j]-'0')+max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}))%1000000007;
                    }
                }
            }
        }
        vector<vector<long long>> dp1(board.size(),vector<long long>(board[0].size()));
        dp1[0][0]=1;
        ok=false;
        for(int i=1;i<board.size();i++){
            if(board[i][0]=='X'){
                ok=true;
            }
            if(!ok){
                dp1[i][0]=1;
            } 
        }
        ok=false;
        for(int i=1;i<board[0].size();i++){
            if(board[0][i]=='X'){
                ok=true;
            }
            if(!ok){
                dp1[0][i]=1;
            } 
        }
        for(int i=1;i<board.size();i++){
            for(int j=1;j<board.size();j++){
                if(board[i][j]=='S'){
                    if(dp[i-1][j]==dp[i][j]){
                        dp1[i][j]+=dp1[i-1][j]%1000000007;
                    }
                    if(dp[i-1][j-1]==dp[i][j]){
                        dp1[i][j]+=dp1[i-1][j-1]%1000000007;
                    }
                    if(dp[i][j-1]==dp[i][j]){
                        dp1[i][j]+=dp1[i][j-1]%1000000007;
                    }
                }else if(board[i][j]!='X'){
                    if(dp[i-1][j]+(board[i][j]-'0')==dp[i][j]){
                        dp1[i][j]+=dp1[i-1][j]%1000000007;
                    }
                    if(dp[i-1][j-1]+(board[i][j]-'0')==dp[i][j]){
                        dp1[i][j]+=dp1[i-1][j-1]%1000000007;
                    }
                    if(dp[i][j-1]+(board[i][j]-'0')==dp[i][j]){
                        dp1[i][j]+=dp1[i][j-1]%1000000007;
                    }
                }
            }
        }
        dp1[dp.size()-1][dp[0].size()-1]=dp1[dp.size()-1][dp[0].size()-1]%1000000007;
        vector<int> ans;
        ans.push_back(dp[dp.size()-1][dp[0].size()-1]);
        ans.push_back(dp1[dp.size()-1][dp[0].size()-1]);
        return ans;
    }
};