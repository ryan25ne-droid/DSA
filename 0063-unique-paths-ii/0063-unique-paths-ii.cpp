class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int m, int n, int row, int col, vector<vector<int>> &dp){
        if(row>=m || col>=n){
            return 0;
        }

        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        if(obstacleGrid[row][col]== 1){
            return dp[row][col]= 0;
        }
//isko destination se pehle check karo cause if destination is blocked then ans should be 0

        if(row== m-1 && col== n-1){
            return dp[row][col]= 1;
        }

        if(row== m-1){
            return dp[row][col]= helper(obstacleGrid, m, n, row, col+1, dp);
        }
        if(col== n-1){
            return dp[row][col]= helper(obstacleGrid, m, n, row+1, col, dp);
        }

        return dp[row][col]= helper(obstacleGrid, m, n, row+1, col, dp)+ helper(obstacleGrid, m, n, row, col+1, dp);

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(obstacleGrid, m, n, 0, 0, dp);        
    }
};