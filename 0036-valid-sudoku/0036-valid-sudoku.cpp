class Solution {
public:
//Problem which I faced is that in my Sudoku problem (24th Lecture)
// we fill the character after checking the board. Here with that
//same code, an element always checks itself and returns false on comparison. We have to skip the particular cell of the element itself.
    bool isValidElement(vector<vector<char>>&board, vector<int>&position){
        int row=position[0];
        int col=position[1];
        int element=board[row][col];

        //Empty element check
        if(element=='.'){
            return true;
        }

        //Row check
        for(int i=0;i<9;i++){
            if(i==col){
                continue;
            }
            else{
                if(board[row][i]==element){
                    return false;
                }
            }
        }
        //column check
        for(int i=0;i<9;i++){
            if(i==row){
                continue;
            }
            else{
                if(board[i][col]==element){
                    return false;
                }
            }
        }
        //Grid check
        int r=row/3;
        int c=col/3;
        for(int i=3*r;i<3*r+3;i++){
            for(int j=3*c;j<3*c+3;j++){
                if(i==row &&j==col){
                    continue;
                }
                else{
                    if(board[i][j]==element){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> position={0,0};
        for (int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                position[0]=i;
                position[1]=j;
                if(isValidElement(board,position)==false){
                    return false;
                }
            }
        }
        return true;        
    }
};