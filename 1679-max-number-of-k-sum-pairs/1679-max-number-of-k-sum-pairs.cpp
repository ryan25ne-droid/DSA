// try using 2 pointers and sorting, or hash map
class Solution {
public:
    int maxOperations(vector<int>& nums, int k){
        int n= nums.size();
        int ans=0; 
        
        sort(nums.begin(), nums.end());
        int start=0;
        int end=n-1;

        while(start<end){
            int sum= nums[start]+nums[end];
            if(sum== k){
                ans++;
                start++;
                end--;
            }
            else if(sum< k){
                start++;
            }
            else{
                end--;
            }
        }
        
        return ans;
    }
};