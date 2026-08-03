class Solution {
public:
    int helper(vector<int>& nums, int idx, vector<int>&dp){
        int diff= nums.size()-idx;
        if(diff<=0){
            return 0;
        }
        if(dp[idx]!= -1){
            return dp[idx];
        }
        int ans1= (diff>0 ? nums[idx] :0) - helper(nums, idx+1, dp);
        int ans2= (diff>0 ? nums[idx] :0) + (diff>1 ? nums[idx+1]:0) -helper(nums, idx+2, dp);
        int ans3= (diff>0 ? nums[idx] :0) + (diff>1 ? nums[idx+1]:0) + (diff>2 ? nums[idx+2]:0) -helper(nums, idx+3, dp);

        return dp[idx]= max(ans1, max(ans2, ans3));
    }

    string stoneGameIII(vector<int>& stoneValue){
        int n= stoneValue.size();
        vector<int> dp(n, -1);
        int ans= helper(stoneValue, 0, dp);  
        if(ans>0){
            return "Alice";
        }

        else if(ans==0){
            return "Tie";
        }

        return "Bob";        
    }
};