class Solution {
public:
    // Helper function to count valid paths from (0,0) to (m-1, n-1) using DP
    int countPaths(const vector<string>& grid, int m, int n) {
        if (grid[0][0] == '#' || grid[m - 1][n - 1] == '#') return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '#') {
                    dp[i][j] = 0;
                    continue;
                }
                if (i>0){
                    dp[i][j] += dp[i-1][j];
                }
                if (j>0){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }

    bool backtrack(vector<string>& grid, int m, int n, int k, int row, int col) {
        int currPaths = countPaths(grid, m, n);
        if (currPaths == k) return true;
        if (currPaths < k) return false;

        int totalCells = m * n;
        for (int r= row; r< m; r++){
            int startCol = (r == row) ? col : 0; // Reset column to 0 for subsequent rows!
            for(int c= startCol; c<n; c++){
                if( (r==0 && c==0) || (r==m-1 && c==n-1)) continue;
// don't block start or end blocks
                grid[r][c]= '#';
                if(backtrack(grid, m, n, k, r, c+1)){
                    return true;
                }
                grid[r][c]= '.'; //backtrack
            }
        }
        return false;
    }

    vector<string> createGrid(int m, int n, int k) {
        // Base case check for 1D grid
         string row= "";
        for(int i=0; i<n; i++){
            row+='.';
        }

        vector<string> grid (m, row);

        if(m==1 || n==1){
            if(k==1){
                return grid;
            }
            return {};
        }

        if (backtrack(grid, m, n, k, 0, 0)) {
            return grid;
        }
        return {};
    }
};