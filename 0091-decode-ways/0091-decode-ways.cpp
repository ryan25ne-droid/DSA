class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0'){
            return 0;
        }
        vector<int>dp(n+1,0); //dp[i] represents no of ways to interpret code upto index i
        //base case
        dp[0]=1, dp[1]=1;
        //dp[0] is necessary because all even strings eventually reduce to it.     
        for(int i=2;i<n+1;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
                int lastTwo=stoi(s.substr(i-2,2));
                if(lastTwo>=10 && lastTwo<=26){
                    dp[i]+=dp[i-2];
                }
            }
            else if(s[i-1]=='0'){
                if(s[i-2]=='1' || s[i-2]=='2'){
                    dp[i]+=dp[i-2];
                }
                else{ //last 2 digits are 00, 30,40 ...
                    dp[i]=0;
                }
            }
        }
        return dp[n];        
    }
};