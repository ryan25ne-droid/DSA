class Solution {
public:
    
    int search(vector<int>& nums, int target){
        int k= 0;

        int start=0;
        int end= nums.size()-1 ;

        while(start< end){
            int mid= start + (end-start)/2;

            if(nums[mid] < nums[end]){
                end= mid;
            }
            else{
                start= mid+1;
            }
        }
        k= start;

        start=0; 
        end= k-1;

        while(start<= end){
            int mid= start + (end-start)/2;

            if(nums[mid]<target){
                start= mid+1;
            }
            else if(nums[mid] == target){
                return mid;
            }
            else{
                end= mid-1 ;
            }
        }

        start= k;
        end= nums.size()-1;

        while(start<= end){
            int mid= start + (end-start)/2;

            if(nums[mid]<target){
                start= mid+1;
            }
            else if(nums[mid] == target){
                return mid;
            }
            else{
                end= mid-1;
            }
        }

        return -1;        
    }
};