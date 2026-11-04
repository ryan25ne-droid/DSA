class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int maxLen= 0;
        int zero= 0;
        int l= 0;

        for(int r= 0; r< n; r++){
            zero+= (nums[r]== 0);

            while(zero> k){
                zero-= (nums[l]== 0);
                l++;
            }
            maxLen= max(maxLen, r- l+ 1);
        }

        return maxLen;        
    }
};