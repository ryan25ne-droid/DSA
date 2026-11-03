class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int n= nums.size();
        unordered_map<int, int> mpp;
        int pref= 0;
        mpp[0]= 1;
        int ans= 0;

        for(int r= 0; r<n; r++){
            pref+= nums[r];
            ans+= mpp[pref- k];
            mpp[pref]++;
        }

        return ans;                       
    }
};

//sliding window logic fails in case of -ve integers also being allowed