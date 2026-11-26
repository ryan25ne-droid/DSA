class Solution {
public:
    pair<int, int> helper(vector<int>& arr, int start, int end, vector<vector<pair<int, int>>> &dp){
        if(start== end){
            return {0, arr[start]};
        }

        if(dp[start][end]!= make_pair(-1, -1)){
            return dp[start][end];
        }

        int ans= INT_MAX;

        for(int k= start; k< end; k++){
            ans= min(ans, (helper(arr, start, k, dp).second)* helper(arr, k+ 1, end, dp).second+ helper(arr, start, k, dp).first+ helper(arr, k+ 1, end, dp).first);
        }

        int maxVal= INT_MIN;

        for(int i= start; i<=end; i++){
            maxVal= max(maxVal, arr[i]);
        }

        return dp[start][end]= {ans, maxVal};
    }

    int mctFromLeafValues(vector<int>& arr) {
// Just like MCM, think in terms of the product. For a n sized array, there are n-1 products (of consecutive pairs only). We have to mimimise them. And we have to keep track of the largest element in each subtree as well. Use vector<vector<pair<int, int>> dp to store the product, maxVal.
        
        int n= arr.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        return helper(arr, 0, n-1, dp).first;        
    }
};