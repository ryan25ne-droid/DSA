class Solution {
public:
    int helper(vector<int>& nums, int start, int end, vector<vector<int>> &dp){
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans= 0;
        for(int i= start; i<=end; i++){
            ans= max(ans, nums[start-1]*nums[i]*nums[end+1]+ helper(nums, start, i-1, dp)+ helper(nums, i+1, end, dp));            
        }
        return dp[start][end]= ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n= nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(nums, 1, n-2, dp);  //the original balloons boundary where n is the new updated size
    }
};