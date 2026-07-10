class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<vector<string>>> dp(n+1, vector<vector<string>>(n+1));
//dp[i][j] stores all strings possible when I have used i open brackets and j closed brackets
        // base case
        dp[0][0].push_back("");

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0 && j==0){
                    continue;
                }
                if(j>i){
                    continue;
                }
                // if i>0 we can place '('
                if(i>0){
                    for(auto &ele: dp[i-1][j]){
                        dp[i][j].push_back(ele + "(");
                    }
                }
                // if j>0 we can insert ')'
                if(j>0){
                    for(auto &ele:dp[i][j-1]) {
                        dp[i][j].push_back(ele + ")");
                    }
                }
            }
        }
        return dp[n][n];
    }
};
