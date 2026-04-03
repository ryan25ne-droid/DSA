class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int freq=nums.size()/3;
        for(auto p:m){
            if(p.second>freq){
                ans.push_back(p.first);
            }
        }
        return ans;        
    }
};