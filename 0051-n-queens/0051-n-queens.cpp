class Solution {
    //Each element of vector<string>board represents a row of the chessboard.
public:
    bool isSafe(vector<string>&board,int row,int col, int n){
    //Vertical safety    
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    //Left Diagonal check
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if (board[i][j]=='Q'){
            return false;
        }
    }
    //Right Diagonal
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void backTrack(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if(isSafe(board,row, col, n)) {
            board[row][col] = 'Q';
            backTrack(row+1, n, board, ans);
            board[row][col] = '.';
        }
    }
}

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backTrack(0,n,board,ans);
        return ans;        
    }
};