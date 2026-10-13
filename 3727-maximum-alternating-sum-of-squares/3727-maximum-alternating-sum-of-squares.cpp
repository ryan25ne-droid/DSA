# define ll long long
class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll> arr(n, 0);
        for(int i = 0; i < n; i++){
            arr[i]= nums[i]*nums[i];
        }

        sort(arr.begin(), arr.end());
        ll ans= 0;
        for(int i= 0; i < n; i++){
            ans+= (i<n/2)? -1ll* arr[i]: arr[i];
        }
        return ans;
    }
};