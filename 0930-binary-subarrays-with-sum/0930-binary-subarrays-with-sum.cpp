class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n= nums.size();
        int pref= 0;
        unordered_map<int, int> mpp;   //storing no of times a sum has appeared

        int ans= 0;
        mpp[0]= 1;

        for(int i= 0; i<n; i++){
            pref+= nums[i];
            ans+= mpp[pref- goal];
            mpp[pref]++;
        }

        return ans;        
    }
};