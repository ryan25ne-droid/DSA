class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n+1,0); //dp[i] stores sum of indexes (0 to i-1) in prefix array
        dp[0]=0;

        for(int i=1;i<n+1;i++){
            dp[i]=dp[i-1]+nums[i-1];
        } 

        int minLen=INT_MAX;

        for(int i=0;i<n;i++){
            int sum= dp[i]+ target;
            int start=i+1;
            int end=n;

            while(start<=end){
                int mid=start+(end-start)/2;
                if(dp[mid]>=sum){
                    minLen= min(mid-i,minLen);
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }           
        } 
        return minLen==INT_MAX ? 0:minLen;     
    }
};