class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum= 0;
        for(int ele: nums){
            sum+=ele;
        }

        if(sum%2!=0){
            return false;
        }

        sum=sum/2;
        vector<bool> dp(sum+1, false);
        dp[0]= true; // sum 0 is always achievable

        for(int ele: nums){
            for(int s=sum;s>=ele; s--){
                dp[s]= dp[s] || dp[s-ele];
            }
        }
        return dp[sum];
    }
};
