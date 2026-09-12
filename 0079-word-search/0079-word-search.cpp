class Solution {
public:
    bool helper(int i, int j,int n, int m,vector<vector<char>>&board,string &word, int k){

        if(k== word.size()-1){
            return true;
        }

        char original= board[i][j];
        board[i][j]= '#';
        int dir[4][2]= {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for(auto& ele: dir){
            int nrow=i +ele[0];
            int ncol= j+ele[1];

            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==word[k+1] && board[nrow][ncol]!= '#'){
                if(helper(nrow, ncol, n, m, board, word, k+1)){
                    return true;
                }                
            }
        }
        board[i][j]= original;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word){
        int n=board.size();
        int m=board[0].size();

//optimisations
        if(word.size() >n*m){
            return false;
        }

        unordered_map<char,int> freqBoard;
        for(auto &row:board){
            for(char c:row){
                freqBoard[c]++;
            }
        }
        for(char c:word){
            freqBoard[c]--;
        }
        for(char c:word){
            if(freqBoard[c] <0) {
                return false;
            }
        }

        bool found= false;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]== word[0]){
                    if(helper(i, j, n, m, board, word, 0)){
                        return true;
                    }              
                }
            }
        } 
        
        return false;       
    }
};