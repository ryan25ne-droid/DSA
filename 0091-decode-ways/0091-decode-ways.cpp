class Solution {
public:
    int helper(string s, int n, vector<int>&dp){
        if(s[0]=='0'){  //we have to handle this separately as length of '0' is one and it can return 1 because of other base cases..
            return 0;
        }

        dp[0]=1;
        dp[1]=1;

        if(n==0 || n==1){
            return 1;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        char last=s[n-1];
        int lastTwo= stoi(s.substr(n-2,2));
//10<=lastTwo is necessary to avoid '00' or'01' or any similar '0X' to pass through
        if (last!= '0') {
            dp[n]= helper(s,n-1,dp); // single digit always allowed
            if (lastTwo >= 10 && lastTwo <= 26) {
                dp[n]+= helper(s,n-2,dp); // two digit allowed only if 10–26
            }
            return dp[n];
        }
        else{ //last digit is 0.
            if (lastTwo==10 || lastTwo==20) {
                dp[n]= helper(s,n-2,dp);
                return dp[n];
            }
            return 0;
        }
    }

    int numDecodings(string s){
        int n=s.size();
        vector<int>dp(n+1,-1);
        return helper(s,n,dp);               
    }
};