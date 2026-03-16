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
            int curr=matrix[row][mid];
            if(curr==target){
                return true;
            }
            else if(curr<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;  
    }
};