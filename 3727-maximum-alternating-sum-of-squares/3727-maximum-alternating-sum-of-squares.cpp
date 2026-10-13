# define ll long long
class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i]= nums[i]*nums[i];
        }

        sort(nums.begin(), nums.end());
        ll ans= 0;
        for(int i= 0; i < n; i++){
            ans+= (i<n/2)? -1ll* nums[i]: nums[i];
        }
        return ans;
    }
};