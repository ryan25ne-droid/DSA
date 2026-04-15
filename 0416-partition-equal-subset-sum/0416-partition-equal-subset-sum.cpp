class Solution {
public:
    bool helper(vector<int>&nums, int n, int sum,vector<vector<int>>&dp){
    //base case
        if(n<=0){
            return false;
        }
        if(sum==0){
            return true;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        int currval=nums[n-1];
        
        if(currval<=sum){
    //include
            bool case1= helper(nums,n-1,sum-currval,dp);            
    //exclude
            bool case2= helper(nums,n-1,sum,dp);
            dp[n][sum]=(case1||case2);
        } 
        else{
    //exclude
            dp[n][sum]= helper(nums,n-1,sum,dp);
        } 
        return dp[n][sum];      
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n; i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(nums,n,sum,dp);               
    }
};

//so the problem in above code is that when i initialise dp with false values and check dp[n][sum]!=false, I imply that if it is false, don't use the dp array. but there is a possibility that the answer for that recursive call has already been calculalted and stored in dp, and now I am not sure whether a false in dp is beccause the given subproblem can't be solved, or whether there hasn't been any attempt to solve it till now