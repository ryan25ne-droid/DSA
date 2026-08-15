class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();

        int start=0; 
        int end= n-1;

        if(n==1){
            return 0;
        }

        if(n==2){
            return (nums[0]< nums[1])? 1: 0;
        }

        while(start<= end){
            int mid= start+ (end-start)/2; 
            if(mid-1>=0 && mid+1 <n && nums[mid]> nums[mid+1] && nums[mid]> nums[mid-1]){
                return mid;
            }
            else if(mid+1<n && nums[mid]< nums[mid+1]){
                start= mid+1;
            }
            else{
                end= mid-1;
            }
        }
        return start;
    }
};