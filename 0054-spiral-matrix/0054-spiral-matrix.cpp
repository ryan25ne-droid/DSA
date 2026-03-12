class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(); 
        int m=matrix[0].size();
        vector<int> ans;
        int left=0;
        int right=m-1;
        int top=0;
        int bottom=n-1;
        while(left<right && top<bottom){
            for(int i=left;i<right;i++){
                ans.push_back(matrix[top][i]);
            }
            for(int i=top;i<bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            for(int i=right;i>left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            for(int i=bottom;i>top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        if(top<bottom){ //left==right
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][left]);
            }
        }
        if(left<right){ //top==bottom
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
        }
        //this takes into account the last element remaining in cases of square matrices, similar to the Q 59
        if(top==bottom && left==right){ 
            ans.push_back(matrix[top][left]);
        } 
        return ans;
    }
};