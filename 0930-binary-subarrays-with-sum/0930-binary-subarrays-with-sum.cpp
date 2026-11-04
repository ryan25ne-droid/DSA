class Solution {
public:
    int atmostK(vector<int>& nums, int k){
        int n= nums.size();
        int l= 0;
        int sum= 0;
        int ans= 0;

        if(k< 0){
            return 0;   //nums has non -ve integers
        }

        for(int r= 0; r< n; r++){
            sum+= nums[r];
            
            while(sum >k){
                sum-= nums[l];
                l++;
            }

            ans+= (r- l+ 1);            
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atmostK(nums, goal)- atmostK(nums, goal- 1);        
    }
};