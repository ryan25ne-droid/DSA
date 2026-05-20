class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if (nums1.size()> nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int n= nums1.size();
        int m= nums2.size();
        int start= 0, end= n;

        while (start<= end){
            int i= (start+ end) / 2;          // partition in nums1
            int j= (n+m+1)/2-i;        // partition in nums2

            int L1= (i==0) ? INT_MIN: nums1[i-1];
            int R1= (i==n) ? INT_MAX: nums1[i];
            int L2= (j==0) ? INT_MIN: nums2[j-1];
            int R2= (j==m) ? INT_MAX: nums2[j];

            if (L1<= R2 && L2<= R1){
                if ((n+m)% 2 == 0){
                    return (max(L1, L2)+ min(R1, R2))/2.0;
                }
                else{
                    return max(L1, L2);
                }
            } 
            else if (L1>R2) {
                end= i-1;
            }
            else {
                start= i+1;
            }
        }
        return -1; // should never reach here
    }
};
