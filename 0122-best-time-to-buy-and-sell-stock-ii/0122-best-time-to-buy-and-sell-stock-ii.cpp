class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
//dp[i][j] represents max profit possible upto day i and state j.
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            dp[i][0]=max(dp[i+1][0], dp[i+1][1]+prices[i]);
            dp[i][1]=max(dp[i+1][1],dp[i+1][0]-prices[i]);
        } 
        return dp[0][1];        //start at day 0, allowed to buy       
    }
};