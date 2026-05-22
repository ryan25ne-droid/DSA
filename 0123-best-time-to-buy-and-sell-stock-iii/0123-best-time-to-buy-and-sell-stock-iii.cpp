class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        //dp[i][j] represents max profit upto day i for state j. j=3 means you haven't buyed anything yet. j=2 means you have buyed one stock now. j=2 means you sold the 1st stock. j=1 means you buyed your last stock. j=0 means you sold your last stock. You can't do anything now/

        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }

        dp[n][4]=dp[n][3]=dp[n][2]=dp[n][1]=dp[n][0]=0;

        for(int i=n-1;i>=0;i--){
            dp[i][4]= max(dp[i+1][4], dp[i+1][3]-prices[i]);
            dp[i][3]= max(dp[i+1][3],dp[i+1][2]+prices[i]);
            dp[i][2]= max(dp[i+1][2],dp[i+1][1]-prices[i]);
            dp[i][1]= max(dp[i+1][1],dp[i+1][0]+prices[i]);
        }

        return dp[0][4];
    }
};