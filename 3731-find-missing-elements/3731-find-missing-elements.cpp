class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums){
        sort(nums.begin(), nums.end());\
        int n= nums.size();
        vector<int> ans;


        for(int i=1; i<n; i++){
            if (nums[i]!= nums[i-1]+1){
                int ele= nums[i-1]+1;
                while(ele<nums[i]){
                    ans.push_back(ele);
                    ele++;
                }
            }
        }  
        return ans;              
    }
};