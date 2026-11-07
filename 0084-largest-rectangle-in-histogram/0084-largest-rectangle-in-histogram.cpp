class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> nse(n, -1);
        vector<int> pse(n, -1);

        int maxArea= 0;
        stack<int> st;  //store indexes

        for(int i= 0; i< n; i++){  //next smaller
            while(!st.empty() && heights[i]< heights[st.top()]){
                nse[st.top()]= i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i= 0; i< n; i++){   //previous smaller
            while(!st.empty() && heights[i]<= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]= st.top();
            }
            st.push(i);
        }
        
        for(int i= 0; i< n; i++){
            int width;
            if(pse[i]!= -1 && nse[i]!= -1){
                width= (nse[i]- pse[i]- 1);
            }

            else if(pse[i]== -1 && nse[i]!= -1){
                width= nse[i];
            }

            else if(nse[i]== -1 && pse[i]!= -1){
                width= n- 1- pse[i];
            }

            else{
                width= n;
            }

            int area= heights[i]* width;
            maxArea= max(maxArea, area);
        }

        return maxArea;
    }
};