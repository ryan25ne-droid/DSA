class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ptr1=0;
        int ptr2=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<int>array(n+m,0);
        int ptr3=0;
        while(ptr1<n && ptr2<m){
            if(nums1[ptr1]<nums2[ptr2]){
                array[ptr3]=nums1[ptr1];
                ptr1++;
            }
            else{
                array[ptr3]=nums2[ptr2];
                ptr2++;
            }
            ptr3++;
        } 
        while(ptr1<n){
            array[ptr3]=nums1[ptr1];
            ptr3++;
            ptr1++;
        } 
        while(ptr2<m){
            array[ptr3]=nums2[ptr2];
            ptr3++;
            ptr2++;
        }   
        if((n+m)%2!=0){
            return array[(n+m)/2];
        }
        return (array[(n+m)/2-1]+array[(n+m)/2])/2.0; //careful with no of elements and indexing of an array
    }
};