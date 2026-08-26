class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        for(int i=m-1; i>=0; i--){
            vector<int> diag;
            
            int row=i;
            int col= 0;
            
            while(row <m && col <n){
                diag.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(diag.begin(), diag.end());
            
            row= i;
            col=0;
            int k=0;
            
            while(row <m && col <n){
                mat[row][col]= diag[k];
                row++;
                col++;
                k++;
            }         
        }
        
        for(int j=1; j<n; j++){
            vector<int> diag;
            
            int row=0;
            int col=j;
            
            while(row< m && col< n){
                diag.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(diag.begin(), diag.end());
            
            row=0;
            col=j;
            int k=0;
            
            while(row< m && col <n){
                mat[row][col]= diag[k];
                row++;
                col++;
                k++;
            }         
        }
        return mat;
    }
};