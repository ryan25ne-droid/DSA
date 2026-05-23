class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int n=nums.size();
//create a prefix sum array. dp[i] stores sum upto index i (including nums[i])
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(dp[i]-(j>0 ? dp[j-1]:0)==k){
                    ans++;
                }
            }
        }
        return ans;               
    }
};