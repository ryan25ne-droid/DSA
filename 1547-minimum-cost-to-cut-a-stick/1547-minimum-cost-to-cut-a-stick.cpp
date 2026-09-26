class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);   //insert n at end

        cuts.insert(cuts.begin(), 0);   //insert 0 at start

        sort(cuts.begin(), cuts.end()); 

        int m= cuts.size(); 

        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
// dp[i][j] represents the minimum cost of performing all cuts that lie strictly b/w cuts[i] and cuts[j]

        // base case
        for(int i=0; i<m-1; i++){
            dp[i][i+1]= 0;
        }

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<m; j++){
        //         for(int idx= i+1; idx<j; idx++){
        //             dp[i][j]= min(dp[i][j], cuts[j]- cuts[i]+ dp[i][idx]+ dp[idx][j]);
        //         }                
        //     }
        // } 
        for(int len=2; len<m; len++){
            for(int i=0; i<m-len; i++){
                int j= i+len;
                for(int idx= i+1; idx<j; idx++){
                    dp[i][j]= min(dp[i][j], cuts[j]- cuts[i]+ dp[i][idx]+ dp[idx][j]);
                }
            }
        }

// biggest hurdle in tabulation- Even after writing memoisation we have to think in what order do we fill this thing. The commented out relation is correct, but here we need dp[i][idx] and dp[idx][j] calculated before dp[i][j]. But the order in which we have written the loops, dp[idx][j] won't be calculated first. So that's a problem.

        return dp[0][m-1];      
    }
};


// for(int idx= i+1; idx<j; idx++){
//     ans= min(ans, cuts[j]- cuts[i]+ helper(i, idx, cuts, dp)+ helper(idx, j, cuts, dp));
// }

