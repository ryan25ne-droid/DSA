class Solution {
public:
    int maxOperations(vector<int>& nums, int k){
        int n= nums.size();
        unordered_map<int, int> mpp;
        int ans=0;

// mpp stores (value, freq)

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        
        for(int i=0; i<n; i++){
            int target= k- nums[i];
            if(target== nums[i]){
                ans+= mpp[target]/2;
                mpp[target]=0;
            }else{
                if(mpp[target]>0){
                    int count= min(mpp[target], mpp[nums[i]]);
                    ans+= count;
                    mpp[target]-= count;
                    mpp[nums[i]]-=count;
                }
            }

        }
        return ans;
    }
};