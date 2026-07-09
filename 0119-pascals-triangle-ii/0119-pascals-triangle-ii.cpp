class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> curr(r+1,0);
        vector<int> prev(r+1,0);

        prev[0]=1;
        curr[0]=1;
        
        for(int i=1;i<=r;i++){
            for(int j=1;j<=i;j++){
                curr[j]=prev[j-1]+prev[j];
            }
            prev=curr;            
        }    
        return curr;  
    }
};