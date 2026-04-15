class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }  
        if(sum%2!=0){
            return false;
        } 
        sum=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
//here dp[i][j] represents whether its possible to obtain sum j using any subset of 1st i elements of the array. 
        
        //Base case. Sum j=0 is always achievable
        for(int i=0; i<n+1; i++){
            dp[i][0]=true;
        }

        for(int i=1; i<=n; i++){  //i keeps track of no of elements used.
            int currval= nums[i-1];
            for(int s=1; s<=sum; s++){  //s keeps track of the sum still left for us to make using elements
                if(currval <=s){
                    dp[i][s] = dp[i-1][s] || dp[i-1][s-currval];
//include- dp[i-1][s-currval],  exclude- dp[i-1][s]
                } else {
//exclude
                    dp[i][s] = dp[i-1][s];
                }
            }
        }
        return dp[n][sum];
    }
};