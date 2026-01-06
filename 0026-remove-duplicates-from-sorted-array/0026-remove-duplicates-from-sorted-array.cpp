class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       //j>i. so condition of stopping on j not i.
       int i=0;
       for(int j=1;j<nums.size();j++){
            if(nums[i]==nums[j]){
            continue;
        }
            else{
                i++;
                nums[i]=nums[j];
            }
       }
        int k=i+1;       
        return k;       
    }
};