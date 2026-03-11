class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int si=0; 
        int ei=n-1;
        int count=1;
        while(si<ei){ //si<=ei is dealt with separately later in if statement
            for(int i=si;i<ei;i++){
                ans[si][i]=count;
                count++;
            }
            for(int i=si;i<ei;i++){
                ans[i][ei]=count;
                count++;
            }
            for(int i=ei;i>si;i--){
                ans[ei][i]=count;
                count++;
            }
            for(int i=ei;i>si;i--){
                ans[i][si]=count;
                count++;
            }
            si++;
            ei--;
        }  
        if(n%2!=0){ //n is odd. which leaves a single element at the end
            ans[si][ei]=count;
        }  
        return ans;                 
    }
};