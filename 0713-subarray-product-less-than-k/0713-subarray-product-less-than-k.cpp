class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        if(k<= 1){
            return 0;
        }
        
        int n= nums.size();
        int l= 0;
        int prod= 1;
        int ans= 0;

        for(int r= 0; r< n; r++){
            prod= prod* nums[r];

            while(prod>= k){
                prod= prod/ nums[l];
                l++;
            }
            ans+= (r- l+ 1);   //no of uncounted subarrays valid b/w l and r is those which end at current r. rest all have been counted previously
        }   

        return ans;     
    }
};