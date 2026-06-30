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
        
        while(k!=0){
            long long x=static_cast<long long>(nums[i]);
            long long y=static_cast<long long>(mul)*nums[i];
            ans+=max(x,y);
            i++;
            mul--;
            k--; 
            if(i>=n){
                break;
            }           
        }

        return ans;        
    }
};