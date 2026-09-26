class Solution {
public:
    int helper(string &s, int start, int end, vector<vector<int>> &dp){
        if(start> end){
            return 0;
        }

        if(dp[start][end]!= -1){
            return dp[start][end];
        }

        if(start== end){
            return dp[start][end]= 1;
        }

        if(s[start]== s[end]){
            return dp[start][end]= 2+ helper(s, start+1, end-1, dp);
        }

        int ans1= helper(s, start+1, end, dp);
        int ans2= helper(s, start, end-1, dp);
        return dp[start][end]= max(ans1, ans2);
    }

    int longestPalindromeSubseq(string s){
        int n= s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 

        helper(s, 0, n-1, dp);      

        return dp[0][n-1];              
    }
};