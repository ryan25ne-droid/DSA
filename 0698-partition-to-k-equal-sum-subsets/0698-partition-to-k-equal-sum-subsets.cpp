class Solution {
public:
    bool helper(vector<int> &dp, vector<int> &nums, int mask, int currsum, int target, int n){

        if(mask== (1<< n)-1){
            return true;
        }

        if(dp[mask] != -1){
            return dp[mask];
        }

        for(int i=0; i<n; i++){
// ith element not used
            if(!(mask & (1<<i))){
                if(nums[i]+ currsum <= target){
                    int nextsum= (nums[i]+ currsum)% target;
                    if(helper(dp, nums, mask | (1<<i), nextsum, target, n)){
                        dp[mask] =true;
                        return true;
                    }
//incase nextsum becomes equal to target, it becomes 0 (another grp completed)
                }
            }
        }
        dp[mask]= false;
        return false;        
    }

    bool canPartitionKSubsets(vector<int>& nums, int k){
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

        int currsum=0;
        int mask=0;
        vector<int> dp((1<<n), -1);

        return helper(dp, nums, mask, currsum, target, n);        
    }
};