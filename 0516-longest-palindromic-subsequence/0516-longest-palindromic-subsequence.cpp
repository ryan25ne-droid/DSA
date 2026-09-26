class Solution {
public:
    int helper(string &s, int start, int end, vector<vector<int>> &dp){
        if(start<0 || end>=s.size()){
            return 0;
        }

        if(dp[start][end]!= -1){
            return dp[start][end];
        }

        if(start== end){
            return dp[start][end]= 1+ helper(s, start-1, end+1, dp);
        }

        if(s[start]== s[end]){
            return dp[start][end]= 2+ helper(s, start-1, end+1, dp);
        }

        int ans1= helper(s, start-1, end, dp);
        int ans2= helper(s, start, end+1, dp);
        return dp[start][end]= max(ans1, ans2);
    }

    int longestPalindromeSubseq(string s){

        int n= s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans= INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                ans= max(ans, helper(s, i, j, dp));  //this has both odd and even palindromes
            }
        }

        return ans;              
    }
};