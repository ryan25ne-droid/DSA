// class Solution {
// public:
//     int singleNumber(vector<int>& nums){
//         int ans=0;
//         for(int bitIdx=0; bitIdx<32; bitIdx++){
//             int count=0;
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i] & (1<<bitIdx)){
//                     count++;
//                 }
//             }
//             if(count%3 !=0){
//                 ans= ans | (1<<bitIdx);
//             }
//         }  
//         return ans;      
//     }
// };

//its TC= O(32*N)

class Solution {
public:
    int singleNumber(vector<int>& nums){
        sort(nums.begin(), nums.end());

        for(int ptr=1;ptr<nums.size(); ptr=ptr+3){
            if(nums[ptr]!=nums[ptr-1]){
                return nums[ptr-1];
            }
        }    
        return nums[nums.size()-1];        
    }
};