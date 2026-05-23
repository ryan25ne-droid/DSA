class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>curr(2,0);
        vector<int>ahead(2,0);
//
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            curr[1]=max(ahead[1], ahead[0]-prices[i]);
            curr[0]=max(ahead[0], ahead[1]+prices[i]-fee);
            ahead=curr;            
        } 
        return curr[1];        //start at day 0, allowed to buy       
    }
};
        
