class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n, -1);
        stack<int> st;  //store indexes

        for(int i= 0; i< n; i++){
            while(!st.empty() && nums[st.top()]< nums[i]){
                ans[st.top()]= nums[i];
                st.pop();
            }
            st.push(i);
        }

        //now stack only has those entries for which the next greatest element in a linear search issn;t possible. We run the loop again without emptying the stack

        for(int i= 0; i< n; i++){
            while(!st.empty() && nums[st.top()]< nums[i]){
                ans[st.top()]= nums[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;        
    }
};