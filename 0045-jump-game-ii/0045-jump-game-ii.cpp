class Solution {
public:
    int helper(vector<int>& nums, int idx, int n, vector<int> &dp){
        if(idx== n-1){
            return dp[idx]= 0;
        }

        if(dp[idx]!= -1){
            return dp[idx];
        }

        int range= nums[idx];
        int ans= INT_MAX;

        for(int i= idx+1; i<= min(idx+ range, n-1); i++){
            int jump= helper(nums, i,  n, dp);
            if(jump!= INT_MAX){
                ans= min(ans, 1+ jump);
            }
        }
        return dp[idx]= ans;
    }

    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);  //max no of jumps needed from i to reach n-1 idx

        return helper(nums, 0, n, dp);
        
    }
};