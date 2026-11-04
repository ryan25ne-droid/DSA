class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
// non -ve integers only. can use sliding window
        int n= nums.size();
        int ans= INT_MAX;
        int l= 0;
        int sum= 0;

        for(int r= 0; r<n; r++){
            sum+= nums[r];
            if(sum>= target){
                while(sum>= target){
                    sum-= nums[l];
                    l++;
                }
                ans= min((r- l+ 2), ans);  //the current (l, r) window sum is less than target for sure. Increase it by 1 to get the >= target length
            }
        }

        return ans== INT_MAX ? 0: ans;        
    }
};