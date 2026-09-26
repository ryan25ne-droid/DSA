class Solution {
public:
    int helper(string& s, int start, int end, vector<vector<int>> &dp){
        if(start<0 || end>=s.size()){
            return 0;
        }

        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        if(s[start]!= s[end]){
            return dp[start][end]= 0;
        }
        
        return dp[start][end]= 1+ helper(s, start-1, end+1, dp);
    }

    int countSubstrings(string s) {
        int n= s.size();
        int count=0;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i=0; i<n; i++){
            count+= helper(s, i, i, dp);  //odd palindromes
            count+= helper(s, i, i+1, dp);  //even palindromes
        }

        return count;               
    }
};