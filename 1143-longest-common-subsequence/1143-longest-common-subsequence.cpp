class Solution {
public:
    int helper(string &text1, string &text2, vector<vector<int>>&dp,int n,int m){
        if(n==0 || m==0){
            return 0;
        }
//DP reusing older computed methods 
        if(dp[n][m]!=-1){
            return dp[n][m];
        }

        if(text1[n-1]==text2[m-1]){
            dp[n][m]= helper(text1,text2,dp,n-1,m-1)+1;
            return dp[n][m];
        }
        else{
            int ans1= helper(text1,text2,dp,n,m-1);
            int ans2= helper(text1,text2,dp,n-1,m);
            dp[n][m]= max(ans1,ans2);
            return dp[n][m];
        }
    }

    int longestCommonSubsequence(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(text1,text2,dp,n,m);
    }
};

//The issue is everytime you use function substring, you allocate fresh memory for that substirng. Which is the reason why you get Time Memory exceeded. Instead use indexes to include/exclude the last character of the string without using the function substring.