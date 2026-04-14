class Solution {
public:
    int helper(int n,vector<int>&costs, vector<int>&dp){
        //n=1 or n=2 wale cases error dete han
        if(n==1){
            return costs[0]+1;
        }
        if(n==2){
            return costs[1]+min(4,2+costs[0]);
        }
        dp[0]=0;
        dp[1]=costs[0]+1;
        dp[2]=costs[1]+ min(1+dp[1],4+dp[0]);

        for(int i=3;i<=n;i++){
            dp[i]=costs[i-1]+min(1+dp[i-1],min(4+dp[i-2],9+dp[i-3]));
        }
        return dp[n];
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return helper(n,costs,dp);                
    }
};