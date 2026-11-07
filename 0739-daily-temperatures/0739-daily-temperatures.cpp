class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;   //store index

        for(int i= 0; i< n; i++){
            while(!st.empty() && temperatures[st.top()]< temperatures[i]){
                answer[st.top()]= i- st.top();
                st.pop();
            }
            st.push(i);
        }

        return answer;                
    }
};