class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<vector<string>>> dp(n+1, vector<vector<string>>(n+1));
//dp[i][j] stores all strings possible when I have i total open brackets and j unmatched open brackets
        // base case
        dp[0][0].push_back("");

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                // if we can place '('
                if (i>0 &&j<n){
                    for(auto &ele: dp[i-1][j+1]){
                        dp[i][j].push_back("(" +ele);
                    }
                }
                // if we can place ')'
                if(j>0){
                    for(auto &ele:dp[i][j-1]) {
                        dp[i][j].push_back(")" +ele);
                    }
                }
            }
        }
        return dp[n][0];
    }
};
