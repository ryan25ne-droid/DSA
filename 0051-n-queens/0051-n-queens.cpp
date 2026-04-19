class Solution {
    //Each element of vector<string>board represents a row of the chessboard.
public:
//     bool isSafe(vector<string>&board,int row,int col, int n){
//     //Vertical safety    
//     for(int i=0;i<row;i++){
//         if(board[i][col]=='Q'){
//             return false;
//         }
//     }
//     //Left Diagonal check
//     for(int i=row,j=col;i>=0&&j>=0;i--,j--){
//         if (board[i][j]=='Q'){
//             return false;
//         }
//     }
//     //Right Diagonal
//     for(int i=row,j=col;i>=0&&j<n;i--,j++){
//         if(board[i][j]=='Q'){
//             return false;
//         }
//     }
//     return true;
// }

bool isSafe(vector<bool>&cols, vector<bool>&diag1, vector<bool>&diag2,int row, int col, int n){
//Use 3 boolean arrays (cols, diag1, diag2) because they give O(1) safety checks. A DP array of unsafe squares is O(n²) memory+ slower lookups, so it’s inefficient.
    return cols[col] && diag1[row-col+n-1] && diag2[row+col];
}
void backTrack(int row, int n, vector<string>&board, vector<vector<string>>&ans,vector<bool>&cols, vector<bool>&diag1, vector<bool>&diag2) {
    if(row==n) {
        ans.push_back(board);
        return;
    }
    for (int col=0; col<n; col++) {
        if(isSafe(cols,diag1,diag2,row,col,n)) {
            board[row][col]='Q';
            cols[col]=false;
            diag1[row-col+n-1]=false;
            diag2[row+col]=false;

            backTrack(row+1,n,board,ans,cols,diag1,diag2);
            board[row][col]='.';
            cols[col]=true;
            diag1[row-col+n-1]=true;
            diag2[row+col]=true;
        }
    }
}

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        vector<bool>cols(n,true);
        vector<bool>diag1(2*n-1,true);
        vector<bool>diag2(2*n-1,true);
        backTrack(0,n,board,ans,cols,diag1,diag2);
        return ans;        
    }
};