class Solution {
public:
    int helper(int n, vector<int>& cuts, int start, int end, vector<vector<int>> &dp){
        // if(end- start== 1){
        //     return 0;
        // }

        if(dp[start][end]!= -1){
            return dp[start][end];
        }

        int ans= INT_MAX;
        bool found= false;

        for(int i= 0; i< cuts.size(); i++){
            if(cuts[i]> start && cuts[i]< end){
                found= true;
                ans= min(ans, end- start+ helper(n, cuts, start, cuts[i], dp)+ helper(n, cuts, cuts[i], end, dp));
            }            
        }

        return dp[start][end]= (found== true)? ans: 0;  //base case is that there isn;t any cut b/w start and end
    }

    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(n+ 1, vector<int>(n+ 1, -1));
        return helper(n, cuts, 0, n, dp);        
    }
};