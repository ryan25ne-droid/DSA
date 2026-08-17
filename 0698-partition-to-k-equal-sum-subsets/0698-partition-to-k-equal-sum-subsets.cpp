class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n= nums.size();
        int sum=0;

        for(int i=0; i<n; i++){
            sum+= nums[i];
        }

        if(sum%k !=0){
            return false;
        }

        int target= sum/k;
        sort(nums.rbegin(), nums.rend());

        if(nums[0]> target){
            return false;
        }

        int totalstates= (1<<n);

        vector<int> dp(totalstates, -1);
        dp[0]= 0;
// base case. empty set has sum 0
        
        for(int mask=0; mask< totalstates; mask++){
            if(dp[mask]==-1){
                continue;
            }
            for(int i=0; i<n; i++){
                if(!(mask & (1<<i))){
                    if( dp[mask]+ nums[i]<= target){
                        int newMask= mask | (1<<i);
                        dp[newMask]= (dp[mask]+ nums[i])% target;
                    }
                }
            }
        }
        return dp[totalstates-1] ==0;  

// dp[mask] stores the current subset sum modulo target for that mask. If dp[mask] == 0, it means the last subset was completed exactly at target. If dp[mask] != 0, it means we ended with a partially filled subset, which is invalid.
    }
};

// The outer loop eventually iterates over all masks from 0 to (1<<n)-1.

// When it reaches newMask, the check if (dp[newMask] == -1) continue; will now pass, because we filled it earlier.

// That means newMask is now considered a reachable state, and we’ll expand it further by trying to add more unused elements.