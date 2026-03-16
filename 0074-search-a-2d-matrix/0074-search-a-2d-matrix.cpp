class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        if(target<matrix[0][0]){
            return false;
        }   
        if(target>matrix[m-1][n-1]){
            return false;
        } 
        int row=0;
        while(target>matrix[row][n-1]){
            row++;
        }
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;  
    }
};