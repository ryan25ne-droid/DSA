// Iski trick yad rakhna. reverse the entire array. then reverse the first k elements. then reverse the remaining elements

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size(); 
        k= k% n;

        reverse(nums.begin(), nums.end());
              
        reverse(nums.begin(), nums.begin()+k);
        
        reverse(nums.begin()+k, nums.end());
                
    }
};