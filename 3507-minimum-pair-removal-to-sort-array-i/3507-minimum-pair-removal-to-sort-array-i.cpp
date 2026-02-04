class Solution {
public:
    bool numssorted(vector<int>& nums){
            for (int i=0;i<nums.size()-1;i++){
                if (nums[i]>nums[i+1]){
                    return false;
                }
            }
            return true;
        }
    int minimumPairRemoval(vector<int>& nums){
        int n=nums.size();
        //Boolean variable is used to track stopping condition.
        
        while(!numssorted(nums)){
            int leastsum=INT_MAX;
            int idx=-1;
            for(int j=0;j<nums.size()-1;j++){
                int currsum=nums[j]+nums[j+1];
                if(currsum<leastsum){
                    idx=j;
                    leastsum=currsum;
                }
            }
            nums[idx]=leastsum;
            nums.erase(nums.begin()+idx+1);                    
            }
        return n-nums.size();
    }
};