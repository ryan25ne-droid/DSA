class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul){
        if(k==0){
            return 0;
        }

        int n=nums.size();
        sort(nums.begin(), nums.end(), greater<int>());  //descending order
        long long ans=0;
        int i=0;
        
        while(k!=0 && i<n){
            long long x= 1LL*nums[i];
            long long y= 1LL *nums[i]*mul;
            ans+=max(x,y);
            i++;
            mul--;
            k--;            
        }

        return ans;        
    }
};