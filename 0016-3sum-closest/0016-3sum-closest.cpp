class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // OPTIMIZATION: Pruning
            int minSum = nums[i] + nums[i+1] + nums[i+2];
            if (minSum > target) {
                if (abs(minSum - target) < abs(closestSum - target)) closestSum = minSum;
             // Since nums is sorted, any further start/end for this i 
            // will only produce LARGER sums, moving further from target.
                continue; 
            }

            int maxSum = nums[i] + nums[n-2] + nums[n-1];
            if (maxSum < target) {
                if (abs(maxSum - target) < abs(closestSum - target)) closestSum = maxSum;
                // Any other start/end for this i will produce smaller sums than maxSum.
                continue;
            }
            int start = i + 1, end = n - 1;
            while (start < end) {
                int currSum = nums[i] + nums[start] + nums[end];
                if (currSum == target) return target;

                if (abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }

                if (currSum < target) {
                    start++;
                    while (start < end && nums[start] == nums[start - 1]) start++;
                } else {
                    end--;
                    while (start < end && nums[end] == nums[end + 1]) end--;
                }
            }
        }
        return closestSum;
    }
};