class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if (n==0){
            return "";
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start=0, maxLen=1;
//dp[i][j] tracks whether the string b/w indexes i and j is a substring or not. Instead of using substrings which we know take a lot of memory, use indexes

        //Base case: single characters for odd palindromes
        for(int i=0; i<n; i++){
            dp[i][i]=true;
        }

        //Base case: two characters for even palindromes
        for(int i=0; i<n-1; i++) {
            if (s[i]== s[i+1]){
                dp[i][i+1]=true;
                start=i;
                maxLen=2;
            }
        }

        // Length >= 3
        for (int len=3; len<=n; len++) {
            for (int i=0; i<=n-len; i++) {
                int j=i+len-1;
                if (s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (len>maxLen) {
                        start=i;
                        maxLen=len;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
