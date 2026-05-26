class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n= rowIndex+1;
        vector<int> curr(n,0);
        vector<int> prev(n,0);

        prev[0]=1;
        curr[0]=1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                curr[j]=prev[j-1]+prev[j];
            }
            prev=curr;            
        }    
        return curr;  
    }
};