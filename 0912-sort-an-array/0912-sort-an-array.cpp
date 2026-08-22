class Solution {
public:
    void merge(vector<int> &nums, int start, int mid, int end){
        vector<int> temp;
        int i= start;
        int j= mid+1;

        while(i<= mid && j<=end){
            if(nums[i] <=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<= end){
            temp.push_back(nums[j]);
            j++;
        }
        int ptr1=0;
        int ptr2= start;

        while(ptr1< temp.size()){
            nums[ptr2]= temp[ptr1];
            ptr2++;
            ptr1++;
        }
    }

    void mergeSort(vector<int> &nums, int start, int end){
        if(start>= end){
            return;
        }

        int mid= start +(end-start)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums){
        mergeSort(nums, 0, nums.size()-1);
        return nums;                
    }
};