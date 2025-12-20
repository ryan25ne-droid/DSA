class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for (int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;  
    }
};

//constant extra space- creating variables is allowed. Don't create a duplicate vector.