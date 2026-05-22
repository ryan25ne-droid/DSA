class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n);
        dp[0]= nums[0];
        int maxSum= dp[0];
        //dp[i] represents max subarray sum of subarray ending at index i.

        for (int i=1; i<n; i++) {
            dp[i]=max(nums[i], dp[i-1]+nums[i]);
            maxSum= max(maxSum, dp[i]);
        }
        return maxSum;
    }
};
