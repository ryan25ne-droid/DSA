class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n= nums.size();
        int ans= 0;
        int l= 0;
        int odd= 0;

        for(int r= 0; r< n; r++){
            odd+= (nums[r]% 2);

            while(odd> k){
                odd-= (nums[l]% 2);
                l++;
            }

            ans+= (r- l+ 1);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k){
        return atmost(nums, k)- atmost(nums, k-1);        
    }
};