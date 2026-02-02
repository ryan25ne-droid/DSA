class Solution {
    //Binary Search is a kind of recursion
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]<nums[end]){ //right half is sorted
                if (nums[mid]==target){
                    return mid;
                }
                else if(target<nums[mid] || target>nums[end]){ 
                    //target is not in right half
                    end=mid-1; //avoides infinite loop condition
                }
                else{ //target might be in the right half
                    start=mid+1; //avoides infinite loop condition
                }
            } 
            else { //left half is sorted
                if (nums[mid]==target){
                    return mid;
                }
                else if(target>nums[mid]||target<nums[start]){
                    //target not in left half
                    start=mid+1; //avoides infinite loop condition
                }
                else{
                    //target might be in the left half
                    end=mid-1; //avoides infinite loop condn
                }
            }        
        } 
    return -1;
    }       
};