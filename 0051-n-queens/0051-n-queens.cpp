class Solution {
public:
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow, vector<int> &upperdiagonal,vector<int> &lowerdiagonal,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1 + col-row]==0){
                leftRow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+col-row]=1;
                board[row][col]='Q';
                solve(col+1,board,ans,leftRow,upperdiagonal,lowerdiagonal,n);
                leftRow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+col-row]=0;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        solve(0,board,ans,leftRow,upperdiagonal,lowerdiagonal,n);
        return ans;
    }
};