class Solution {
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
int backTrack(int row, int n, vector<string>& board) {
    if (row == n) {
        return 1;
    }
    int count=0;
    for (int col = 0; col < n; col++) {
        if(isSafe(board,row, col, n)) {
            board[row][col] = 'Q';
            count+=backTrack(row+1, n, board);
            board[row][col] = '.';
        }
    }
    return count;
}
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return backTrack(0,n,board);
    }
};
