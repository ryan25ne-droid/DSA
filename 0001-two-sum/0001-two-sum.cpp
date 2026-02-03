class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ans;
       map<int,int> mpp;
       int n=nums.size();
       for(int i=0;i<n;i++){
           mpp[nums[i]]=i;
       }
       for(int i=0;i<n;i++){
           int x=target-nums[i];
           if (mpp.count(x) && mpp[x]!=i){
               ans.push_back(i);
               ans.push_back(mpp[x]);
               return ans;
            }
        }
        return ans;
    }
};