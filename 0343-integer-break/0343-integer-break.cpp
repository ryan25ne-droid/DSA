class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,0); //dp[i] stores the max possible product possible from the number i. 

        dp[1]=1; //base case
        for(int i=2;i<n+1;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],j*max(dp[i-j],i-j));
            }
        }
        return dp[n];
    }
};