class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,0);
        //dp[i] represents min price before day i.
        int profit=0;
        dp[0]=prices[0];
        for(int i=1;i<n;i++){
            dp[i]=min(dp[i-1],prices[i]);
        }
        for(int i=0;i<n;i++){
            profit=max(profit,prices[i]-dp[i]);
        } 
        return profit;               
    }
};