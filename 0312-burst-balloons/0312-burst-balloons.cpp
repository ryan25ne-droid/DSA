class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n= nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // dp[i][j]= max(dp[i][k-1]+ dp[k+1][j]+ nums[k]*nums[i-1]*nums[j+1])
// we need smaller intervals to be calculated first. And they range from smaller to larger indexes. So go by length
        for(int len=1; len <= n-2; len++){
            for(int i=1; i<=n-1-len; i++){
                int j= i+len-1; 

// Try every balloon k in [i, j] as the LAST one to burst in this interval
                for(int k= i; k<=j; k++){
                    dp[i][j]= max(dp[i][j], dp[i][k-1]+ dp[k+1][j]+ nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }
        return dp[1][n-2];
    }
};

// class Solution {
// public:
//     int helper(vector<int>& nums, int start, int end, vector<vector<int>> &dp){
//         if(dp[start][end]!=-1){
//             return dp[start][end];
//         }
//         int ans= 0;
//         for(int i= start; i<=end; i++){
//             ans= max(ans, nums[start-1]*nums[i]*nums[end+1]+ helper(nums, start, i-1, dp)+ helper(nums, i+1, end, dp));            
//         }
//         return dp[start][end]= ans;
//     }

//     int maxCoins(vector<int>& nums) {
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);
//         int n= nums.size();

//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         return helper(nums, 1, n-2, dp);  //the original balloons boundary where n is the new updated size
//     }
// };