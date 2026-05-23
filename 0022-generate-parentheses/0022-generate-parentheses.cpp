class Solution {
public: 
    vector<string> helper(vector<vector<vector<string>>>&dp, int i, int j){
        if(dp[i][j].empty()!=true){
            return dp[i][j];
        }
        else if(i==0 &&j==0){
            dp[i][j].push_back("");
            return dp[i][j];
        }
        if(i==0 && j>0){
            for(auto& ele:helper(dp,i,j-1)){
                dp[i][j].push_back(")"+ ele);
            }
        }
        else if(i>0 && j==0){
            for(auto&ele :helper(dp,i-1,j+1)){
                dp[i][j].push_back("("+ele);
            }
        }
        else{ //i and j non zero
            for(auto&ele: helper(dp,i-1,j+1)){
                dp[i][j].push_back("("+ele);
            }
            for(auto&ele:helper(dp,i,j-1)){
                dp[i][j].push_back(")"+ele);
            }
        }
        return dp[i][j];
    }
    
    vector<string> generateParenthesis(int n){
        vector<vector<vector<string>>> dp(n+1,vector<vector<string>>(n+1));      
//dp[i][j] means possible unique strings given i no of open parenthesis remaining with us and j is no of (open parenthesis-close parenthesis). i starts from n and as soon as it reaches 0 we can only print closed parenthesis. When j=0, you can only print open parenthesis.
        return helper(dp,n,0);        
    }
};