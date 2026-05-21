class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        //dp[i][j] represents whether its possible to convert pattern (0 to j-1 index) into text (0 to i-1 index).
        dp[0][0]=true; //base case. it is always possible to convert an empty pattern into an empty string

        for(int j=1;j<m+1;j++){ //initialising 0th row, i.e. ways for making empty string.
            if(p[j-1]=='*'){
                dp[0][j]=dp[0][j-1];
            }
            else{ // its ? or english character
                dp[0][j]=false;
            }
        }
        for(int i=1;i<n+1;i++){  //you can't create a string from an empty pattern except the empty string itself
            dp[i][0]=false;
        }

        for(int i=1; i<n+1;i++){
            for(int j=1;j<m+1;j++){
                char schar=s[i-1];
                char pchar=p[j-1];
                if(pchar==schar || pchar=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pchar=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j]=false; //islo hata bhi skte since we initialised all cells in dp to false
                }
            }
        }

        return dp[n][m];
    }
};