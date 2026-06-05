class Solution {
public:
    bool helper(int i, int j,int n, int m,vector<vector<char>>&board,string &word,vector<vector<bool>>&visited, int k){
        if(k==word.size()-1){
            return true;
        }
        bool ans;

        visited[i][j]=true;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto&ele: dir){
            int nrow=i +ele[0];
            int ncol= j+ele[1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==word[k+1] && !visited[nrow][ncol]){
                ans=helper(nrow,ncol,n,m,board,word,visited,k+1);
                if(ans==true){
                    return ans;
                }
            }
        }
        visited[i][j]=false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word){
        int n=board.size();
        int m=board[0].size();
        bool found=false;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    found=helper(i,j,n,m,board,word,visited,0);
                    if(found==true){
                        return true;
                    }                    
                }
            }
        } 
        return false;       
    }
};