//logic of this ques is same as Longest Common Substring b/w 2 strings. Which is a difficult concept but not a leetcode question.

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n, vector<int>(m,0));
//dp[i][j] denotes longest substring ending at idx i of str1 and idx j of str2
        int maxLen=0; 
        for(int i=0; i<n; i++){
            if(nums2[0]==nums1[i]){
                dp[i][0]=1;
                maxLen=1;
            }
        }
        for(int i=0; i<m; i++){
            if(nums1[0]==nums2[i]){
                dp[0][i]=1;
                maxLen=1;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(nums1[i]==nums2[j]){
                    dp[i][j]= 1+dp[i-1][j-1];
                    maxLen= max(maxLen, dp[i][j]);

                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return maxLen;        
    }
};