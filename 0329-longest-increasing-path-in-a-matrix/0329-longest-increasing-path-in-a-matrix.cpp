//recStack is not required. Cause of the condition of strictly greater than or equal to, no movement in cycle is ever possible.
class Solution {
public:
    int helper(vector<vector<int>>&matrix, int i, int j, int n, int m, vector<vector<int>>&dp){

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

        for(auto &ele: dir){
            int nrow= i+ele[0];
            int ncol= j+ele[1];

            if(nrow>=0 && nrow<n && ncol >=0 && ncol<m){
                int path= (matrix[i][j]<matrix[nrow][ncol])? 1+helper(matrix, nrow, ncol, n, m, dp) :0; 
                dp[i][j]=max(dp[i][j], path);                
            }
        }
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        int ans= 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,helper(matrix, i,j,n, m, dp));
            }
        }
        return ans+1; //add 1 as the path length counts the starting cell too        
    }
};

//this is very similar to no of Islands Q 200. 