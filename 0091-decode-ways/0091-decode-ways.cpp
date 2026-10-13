class Solution {
public:
    int helper(string &s, int n, int idx, vector<int>& dp){
        if(idx>=n){
            return 1;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        string temp = "";
        int ans=0;

        for(int i= idx; i<min(idx+2, n); i++){
            temp += s[i];
            if(temp[0] == '0') break;
            int no= stoi(temp);

            if(no> 26 || no <=0){
                break;
            }
            ans += helper(s,n, i+1, dp);
        }
        return dp[idx]= ans;
    }
    int numDecodings(string s){
        int n= s.size();
        string temp;
        vector<int> dp(n, -1);

        return helper(s, n, 0, dp);
    }
};