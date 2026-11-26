class Solution {
public:
//     int helper(vector<int>& cuts, int start, int end, vector<vector<int>> &dp){
//         if(end- start== 1){
//             return 0;
//         }
//         if(dp[start][end]!= -1){
//             return dp[start][end];
//         }

//         int ans= INT_MAX;

// // k doesn't mean we are cutting at position k. But rather inside the cuts array, we are cutting at cuts[k] position, which makes 2 segments, from cuts[start] to cuts[k] and from cuts[k] to cuts[end]. k must be strictly b/w start and end

//         for(int k= start+ 1; k< end; k++){
//             ans= min(ans, cuts[end]- cuts[start]+ helper(cuts, start, k, dp)+ helper(cuts, k, end, dp));
//         }

// // In MCM, the split matrix belongs to exactly one side. Here the cut posn becomes the boundary of both resulting segments.
//         return dp[start][end]= ans;
//     }

    int minCost(int n, vector<int>& cuts) {
// once you recognise the similarities with MCM DP, remember how you thought in that. You had a dimensions vector but you thought  in terms of array. Similarly we have been given cut positions but we should think in terms ofsegments we can generate, bounded by 2 cuts. For that we need to add 0 and n as well to the cuts.

        cuts.push_back(0);
        cuts.push_back(n);
        int m= cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        sort(cuts.begin(), cuts.end());

// len 1 is base case. return 0. so fill dp with 0
        for(int len= 2; len< m; len++){
            for(int i= 0; i< m- len; i++){
                int j= i+ len;
                dp[i][j]= INT_MAX;
                for(int k= i+ 1; k< j; k++){
                    dp[i][j]= min(dp[i][j], cuts[j]- cuts[i]+ dp[i][k]+ dp[k][j]);
                }
            } 
        }

        return dp[0][m-1];
    }
};