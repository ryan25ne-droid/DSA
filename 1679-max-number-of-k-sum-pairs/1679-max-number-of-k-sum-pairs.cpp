class Solution {
public:
    int maxOperations(vector<int>& nums, int k){
        int n= nums.size();
        unordered_map<int, int> mpp;
        int ans=0;

// mpp stores (value, freq)

        for(int i=0; i<n; i++){
            int target= k- nums[i];
            if(mpp[target]>0){
                mpp[target]--;
                ans++;
            }
            else{
                mpp[nums[i]]++;
            }
        }
        return ans;
    }
};