class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //dp[i][j] represents no of lines b/w 0 to i-1 idx and 0 to j-1 idx of nums1 and nums2.
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i][j-1], dp[i-1][j]); //this is very similar to excluding last character of any one string in LCS
                }
            }
        }
        return dp[n][m];        
    }
};

//Initially I thought if nums1[i]==nums1[i-1] and there is a match of nums1[i] with an element say k, then k also matches with nums1[i-1] and would be included in that line. SO it can't form any line now with nums1[i].

//So I wrote condition if(nums1[i-1]==nums2[j-1] && nums1[i]!=nums1[i-1] && nums2[j]!=nums2[j-1])

//but think of it as LCS formulation. Since on finding a match we move diagonally, there is no chance that k would even be compared with nums[i] if it matched with nums[i-1].