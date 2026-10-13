class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        for(int i = 0; i < n; i++){
            arr[i] = nums[i]*nums[i];
        }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(i < n/2){
                ans -= arr[i];
            }
            else{
                ans += arr[i];
            }
        }
        return ans;
    }
};