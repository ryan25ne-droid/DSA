class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //dp[i][j] stores min no of opeations to match upto 0 to i-1 idx of word1 to 0 to j-1 idx of word2.
        for(int i=0;i<n+1;i++){
            dp[i][0]=i;
        }      
        for(int j=0;j<m+1;j++){
            dp[0][j]=j;
        } 
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
                }
            }
        }  
        return dp[n][m];  
    }
};