class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int si=0,ei=n;

        while(si<ei){
            int mid=si+(ei-si)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                ei=mid;
            }
            else{
                si=mid+1;
            }
        }
        return si;        
    }
};