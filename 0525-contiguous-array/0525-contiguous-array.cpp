class Solution {
public:
    int findMaxLength(vector<int>& nums){
// best trick. Replace 0-> -1 and 1 as it is
        int n= nums.size();

        for(int i= 0; i<n; i++){
            nums[i]= (nums[i]== 0)? -1: 1;
        }

// now equal no of 1's and -1's means that whenever prefix[i]= prefix[j+1], then the sum of elements in [i, j] is 0. That's a subarray with equal -1(0) and 1
        
        unordered_map<int, int> mpp;
        mpp[0]= -1;    // not including any element (and thus starting at idx= -1) is a valid way of getting sum 0

        int maxLen= 0;
        int pref= 0;

        for(int i= 0; i<n; i++){
            pref+= nums[i];

            if(mpp.find(pref)!= mpp.end()){
                // maxLen= max(maxLen, i- mpp[pref]+ 1);
// ideally for a range [l, r] the len is r- l+ 1 and sum is pref[r+1]- pref[l]. put r+1= i and l= pref. len is i- pref
                maxLen= max(maxLen, i- mpp[pref]);
            }
            else{
                mpp[pref]= i;  //1st pccurence
            }            
        }

        return maxLen;                
    }
};