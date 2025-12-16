class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //We want A+B+C=0. We are doing B+C=-A.
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
            for (int i=0;i<n;i++){
            int x=nums[i];
            int target=-x;

            //Hint 1 actually helped.
            int start=i+1,end=n-1;

         //   if (i<n-1 && nums[i]==nums[i+1]){
              //  continue; 
              //The above code is inefficient because although no duplicates creep in, if i++ and we are checking with the next element, we miss on valid triplets (eg. [-1,-1,2]). So we check from previous element.

              //If i-- from n-1 to 0, nums[i]==nums[i+1] would be the valid logic!

            if (i>0 && nums[i]==nums[i-1]){
               continue;  // Avoid Duplicates for A and avoids going out of bounds.
            }
            
            while (start<end){
                int currsum=nums[start]+nums[end];
                if (currsum==target){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++; 
                    end--;
                  //remember array is sorted. If we move only one pointer then we always get a smaller/larger number than target no.

    // Look back at start-1 because we already did start++               

                while (start < end && nums[start] == nums[start-1]) {
                    start++;
                }
  // Look forward at end+1 because we already did end--
                    while (start < end && nums[end] == nums[end+1]) {
                        end--;  
                    }     
                }
                else if (currsum<target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
    return ans;
    }
};