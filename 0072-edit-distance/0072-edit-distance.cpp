class Solution {
public:
    int helper(string &word1, string &word2, int i, int j,  vector<vector<int>> &dp){
        if(i== -1 && j== -1){
            return 0;
        }
        if(i== -1 && j!= -1){
            return j+ 1;   // insert remaining char
        }
        if(i!= -1 && j== -1){
            return i+ 1;   // delete remaining char
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }

        if(word1[i]== word2[j]){
            return dp[i][j]= helper(word1, word2, i-1, j-1, dp);
        }
        
        int replace= 1+ helper(word1, word2, i-1, j-1, dp);
        int del= 1+ helper(word1, word2, i-1, j, dp);
        int insert= 1+ helper(word1, word2, i, j-1, dp);

        return dp[i][j]= min(replace, min(del, insert));

    }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();

        if(n== 0){
            return m;
        }

        if(m== 0){
            return n;
        }

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(word1, word2, n-1, m-1, dp);        
    }
};