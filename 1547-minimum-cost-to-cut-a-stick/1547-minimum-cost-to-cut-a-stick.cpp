class Solution {
public:
    int helper(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i+1 ==j){
            return 0;
        } 

        if(dp[i][j]!= -1){
            return dp[i][j];
        }

        int ans= INT_MAX;

        for(int idx= i+1; idx<j; idx++){
            ans= min(ans, cuts[j]- cuts[i]+ helper(i, idx, cuts, dp)+ helper(idx, j, cuts, dp));
        }

        return dp[i][j]= ans;
    }

    int minCost(int n, vector<int>& cuts) {
        // vector<int> interval;
        // interval.push_back(0);

        // for(int i=0; i<cuts.size(); i++){
        //     interval.push_back(cuts[i]);
        // }
        // interval.push_back(n);

        // sort(interval.begin(), interval.end());

        // int ptr1=0;
        // int ptr2= interval.size()-1;

        cuts.push_back(n);   //insert n at end

        cuts.insert(cuts.begin(), 0);   //insert 0 at start

        sort(cuts.begin(), cuts.end()); 

        int m= cuts.size(); 

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return helper(0, m-1, cuts, dp);        
    }
};