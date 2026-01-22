class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr3=m;
        for(int ptr4=0;ptr4<n;ptr4++){
            nums1[ptr3]=nums2[ptr4];
            ptr3++;
        }
        //ptr2 increase karega. ptr1 decrease karega.
        for(int ptr2=m;ptr2<m+n;ptr2++){
            for(int ptr1=ptr2-1;ptr1>-1;ptr1--){
                if(nums1[ptr1]>nums1[ptr2]){
                    swap(nums1[ptr1],nums1[ptr2]);
                    ptr2--;
                }
            }
        }
        for(int i=0;i<m+n;i++){
            cout<<nums1[i]<<" ";
        }
    }
};