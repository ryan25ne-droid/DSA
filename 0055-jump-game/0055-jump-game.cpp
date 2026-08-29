class Solution {
public:
    bool helper(vector<int>& nums, int idx, vector<char>& dp){
        if(dp[idx]!= -1){
            return dp[idx];
        } 

        if(idx== nums.size()-1){
            return dp[idx]= true;
        }
        int ele= nums[idx];

        for(int i=1; i<= ele; i++){
            if(helper(nums, idx+i, dp)){
                return dp[idx]= true;
            }
        }
        return dp[idx]= false;
    }

    bool canJump(vector<int>& nums){
        int n= nums.size();
        vector<char> dp(n, -1);
        return helper(nums, 0, dp);                
    }
};