class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size();
        int ans= 0;
        unordered_map<int, int> mpp;  //storing the modulo, no of arrays
        int pref= 0;
        mpp[0]= 1;  

        for(int i= 0; i<n; i++){
            pref+= nums[i];

            // for(int j= 0; j<= pref/k; j++){
            //     ans+= mpp[pref- j* k];
            // }
            ans+= mpp[(pref% k + k) % k];
            mpp[(pref% k+ k)% k]++;
        }
        return ans;             
    }
};

//dealing with mod in C++
// In C++ -1% 5= -1. But in maths, -1% 5= 4. so we have to account for that by adding extra 5 and then taking mod.