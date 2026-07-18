//logic of this ques is same as Longest Common Substring b/w 2 strings. Which is a difficult concept but not a leetcode question.

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
//Instead of using the 2-D dp array, try using the 2 1-D arrays. This is done if in the dp relation, we depend only on the previous rows.

        vector<int> curr(m+1,0), prev(m+1,0);
//chose m+1 size cause we run the inner loop till m. Try to imagine why
        int maxLen=0; 

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(nums1[i-1]==nums2[j-1]){
                    curr[j]= 1+prev[j-1];
                    maxLen= max(maxLen, curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return maxLen;        
    }
};