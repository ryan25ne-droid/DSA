class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>>dp(n);
    
        for(int i=0;i<n;i++){
            dp[i].resize(i+1);     // new function unlocked. each row has only i+1 columns. eg 0th row has 1 col, 1st row has 2 col etc..
            dp[i][0]=dp[i][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<i;j++){
                dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp;                
    }
};