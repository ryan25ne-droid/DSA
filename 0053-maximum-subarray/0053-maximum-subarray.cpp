class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=nums[0];
        int max_sum=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_sum+=nums[i];
            if(curr_sum<=0){
                curr_sum=0;
            }
            if(curr_sum>max_sum){
                max_sum=curr_sum;
            }            
        }  
        return max_sum;      
    }
};