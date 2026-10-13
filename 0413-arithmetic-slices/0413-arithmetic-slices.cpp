class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& dp){
        if(i< 2){
            return 0;
        } 

        if(dp[i]!= -1){
            return dp[i];
        }

        int count= 0;
        if(nums[i]- nums[i-1] == nums[i-1]- nums[i-2]){
            count= 1+ helper(nums, i-1, dp);
        }
        
        return dp[i]= count;       
    }

    int numberOfArithmeticSlices(vector<int>& nums){
        int n= nums.size();
        if(n<3){
            return 0;
        }
        
        vector<int> dp(n, -1);
        int ans= 0;
        
        // Sum up the slices ending at every possible index from 2 to n-1
        for(int i= 2; i< n; i++) {
            ans+= helper(nums, i, dp);
        }
        
        return ans;        
    }
};