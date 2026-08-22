class Solution {
public:
    
    void merge(vector<int> &nums, int start, int mid, int end, vector<int>& temp){
        int ptr1= start;
        int ptr2= mid+1;
        int ptr3= start;

        while(ptr1 <= mid && ptr2 <=end){
            if(nums[ptr1] <=nums[ptr2]){
                temp[ptr3++]= nums[ptr1++];
            }
            else{
                temp[ptr3++]= nums[ptr2++];
            }
        }
        while(ptr1<=mid){
            temp[ptr3++]= nums[ptr1++];
        }
        while(ptr2<= end){
            temp[ptr3++]= nums[ptr2++];
        }
        
        for(int i= start; i<=end; i++){
            nums[i]= temp[i];
        }
    }

    void mergeSort(vector<int> &nums, int start, int end, vector<int>& temp){
        if(start>= end){
            return;
        }

        int mid= start +(end-start)/2;
        mergeSort(nums, start, mid, temp);
        mergeSort(nums, mid+1, end, temp);
        merge(nums, start, mid, end, temp);
    }

    vector<int> sortArray(vector<int>& nums){
        int n= nums.size();
        vector<int> temp(n);
        mergeSort(nums, 0, n-1, temp);
        return nums;                
    }
};