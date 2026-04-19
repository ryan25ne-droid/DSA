class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
//dp[i] represents min no of coins needed to achieve i amount
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,amount+1);
//initializing the vector here is tricky.You are using min to update the function. so initializing with 0 would set all dp[i] to 0. if you use INT_MAX for dp[i] for all i=0 to n, then dp[i]+1 is INT_MAX+1. Overflow. So you initialise with amount+1. Since smallest coin is 1, you can never use more than amount coins in any case
        dp[0]=0; //base case. You need 0 coins to achieve 0 amount
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if (coins[j]<=i) {
//avoid accessing -ve index in dp[i-coins[j]]
                    if (dp[i-coins[j]]!=amount+1){
//Only update if the remainder was actually reachable! 
                        dp[i]=min(dp[i],1+dp[i-coins[j]]);
                    }
                }
                else {
//Since coins are sorted, no need to check the rest
                    break; 
                } 
            }                          
        }
        if(dp[amount]==amount+1){
            return -1;
        }  
        return dp[amount];              
    }
};