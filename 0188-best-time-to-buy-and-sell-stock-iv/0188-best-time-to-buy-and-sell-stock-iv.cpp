class Solution {
public:
    int maxProfit(int k, vector<int>& prices){
        int n=prices.size();
        vector<int>curr(2*k+1,0);
        vector<int>next(2*k+1,0);  //the maximum profit possible from next day upto the end of the trading. It has k+1 states signifying different stages in DP. 2*k means you  haven't engaged in any transaction. 2*k-1 means you have engaged in buying 1st stock. and similarly you continue until state 0means you can't do anything.

//next is initialised to 0 because initially it represents last day, where your profit after that is 0 no matter cause trading stops.
        for(int i=n-1;i>=0;i--){
            for(int j=2*k; j>=1;j--){
                if(j%2==0){
                    curr[j]=max(next[j], next[j-1]-prices[i]);
                }
                else{ //if you go from odd to even (from j to j+1 if j is odd) you sell. And hence add prices[i] to your profit.
                    curr[j]=max(next[j],next[j-1]+prices[i]);
                }
            }
            // for(int j=2*k-1; j>=0;j--){
            //     next[j]=curr[j];
            // }
            next=curr;
        }        

        return curr[2*k];                
    }
};