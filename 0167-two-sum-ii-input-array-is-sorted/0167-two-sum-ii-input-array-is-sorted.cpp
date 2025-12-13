class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0,end=numbers.size()-1;
        while (start<end){
            int cursum=numbers[start]+numbers[end];
            if (cursum==target){
            return {start+1,end+1};
            }    
            else if (cursum<target){
                start++;
            }   
            else{
                end--;
            }   
        }
           return {};
    }
};
    