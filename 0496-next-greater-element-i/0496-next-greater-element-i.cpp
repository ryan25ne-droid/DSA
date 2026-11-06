class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int n= nums1.size();
        int m= nums2.size();
        vector<int> ans(n, -1);

        vector<int> great(m, -1);  //store next greater for every element in nums2

        stack<int> st;

        for(int i= m-1; i>= 0; i--){
            while(!st.empty() && st.top()< nums2[i]){
                st.pop();
            }

            if(!st.empty()){
                great[i]= st.top();
            }

            st.push(nums2[i]);          
        }

        for(int i= 0; i< n; i++){
            int idx= 0;
            while(nums1[i]!= nums2[idx]){
                idx++;
            }
            ans[i]= great[idx];
        }

        return ans;
    }
};