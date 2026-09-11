class Solution {
public:
    int helper(vector<vector<int>>& grid, int m, int n, int row, int col, vector<vector<int>> &dp){
        if(row== m-1 && col== n-1){
            return dp[row][col]= grid[row][col];
        }
        if(row>=m || col>=n){
            return INT_MAX;   //a large cost
        }

        if(dp[row][col]!= -1){
            return dp[row][col];
        }

        return dp[row][col]= grid[row][col]+ min(helper(grid, m, n, row+1, col, dp), helper(grid, m, n, row, col+1, dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(grid, m, n, 0, 0, dp);       
    }
};