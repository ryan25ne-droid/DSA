class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        } 
        int ans=0;
        for( auto ele : m){
            if(ele.second>nums.size()/2){
                ans= ele.first;
                break;
            }
        } 
        return ans;      
    }
};