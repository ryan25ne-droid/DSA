class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // int oddCount = 0, evenCount = 0;
        // for (int num : nums1) {
        //     if (num % 2 == 0) {
        //         evenCount++;
        //     }
        //     else{
        //         oddCount++;
        //     }       
        // }
        // // Case 0: already uniform
        // if (oddCount == 0 || evenCount == 0) return true;

        // // Case 1- all even possible if at least two odds exist
        // if (oddCount >= 2){
        //     return true;
        // }

        // // Case 2:all odd possible if at least one odd and one even exist
        // if (oddCount >= 1 && evenCount >= 1){
        //     return true;
        // }
        // return false;
        return true;
    }
};