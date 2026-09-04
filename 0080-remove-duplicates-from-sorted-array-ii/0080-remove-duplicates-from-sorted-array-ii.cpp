class Solution {
public:
    int removeDuplicates(vector<int>& nums){

        int n= nums.size();
        vector<bool> atTwice(n, false); 

        int ptr1 =0;

        for(int ptr2=1; ptr2<n; ptr2++){
            if(nums[ptr2] == nums[ptr2-1]){
                atTwice[ptr2]= true;

                if(atTwice[ptr2-1]){
                    continue;
                }
            } 

            ptr1++;
            nums[ptr1]= nums[ptr2];
        }  

        return ptr1+1;              
    }
};