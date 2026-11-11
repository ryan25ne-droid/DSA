class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
// using k largest elements
        int n= nums.size();
        priority_queue<int> pq;

        for(int i= 0; i< n; i++){
            pq.push(nums[i]);
        }

        for(int i= 0; i< k-1; i++){  //remove k-1 elements
            pq.pop();
        }

        return pq.top();        
    }
};