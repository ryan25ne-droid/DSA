class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
// using min heap for k largest elements
        int n= nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x: nums){
            pq.push(x);

            if(pq.size()> k){
                pq.pop();
            }
        }

        return pq.top();        
    }
};

// min heap keeps the smallest elements at top. If its size< k, we push element in it. If its size> k, we pop the top element. That means the smaller element is popped (the larger element sinks deeper into the heap). At the end the heap contains the k largest elements, with the smallest of them all (i.e. kth largest element) at the very top