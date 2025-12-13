class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int actual_sum=n*(n+1)/2;

        int currsum=0;
        for (int i=0;i<nums.size();i++){
            currsum+=nums[i];
        }
        
        vector<int> ans(2);

        int duplicate=-1;

        for (int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                duplicate=nums[i];
                ans[0]=duplicate;
                ans[1]=actual_sum-currsum+duplicate; 
                break;            
            }
        } 
        return ans;       
    }
};