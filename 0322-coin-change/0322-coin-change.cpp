auto fastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
//dp[i] represents min no of coins needed to achieve i amount
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,amount+1);
//initializing the vector here is tricky.We use min to update dp[i]. So initializing with 0 would set all dp[i] to 0. if we use INT_MAX for dp[i] for all i=0 to n, then dp[i]+1 is INT_MAX+1. Overflow. So initialise with amount+1. Since smallest coin is 1, we can never use more than amount coins in any case.
        dp[0]=0; //base case. You need 0 coins to achieve 0 amount
        for(int i=1;i<=amount;i++){
            for(int ele:coins){
                if (ele<=i && dp[i-ele]!=amount+1){
//avoid accessing -ve index in dp[i-coins[j]] and only update if the remainder was actually reachable! 
                    dp[i]=min(dp[i],1+dp[i-ele]);
                }
            }                          
        }
        if(dp[amount]==amount+1){
            return -1;
        }  
        return dp[amount];              
    }
};