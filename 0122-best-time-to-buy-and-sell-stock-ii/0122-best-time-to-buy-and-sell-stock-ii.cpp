class Solution {
public:
    int helper(vector<int>&prices, vector<vector<int>>&dp, int day, int state, int n){
        if(dp[day][state]!=-1){
            return dp[day][state];
        }
        if(day==n){
            return 0;
        }
        if(state==0){
            return dp[day][state]=max(helper(prices,dp,day+1,0,n),helper(prices,dp,day+1,1,n)+prices[day]);
        }
        else{ //state=1;
            return dp[day][state]=max(helper(prices,dp,day+1,1,n), helper(prices,dp,day+1,0,n)-prices[day]);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
//dp[i][j] stores max profit possible to make on upto day i with state j. j=1 means you can buy stock. j=0 means you can't buy new stock cause you are already holding one. You must sell it.
        return helper(prices,dp,0,1,n);                
    }
};