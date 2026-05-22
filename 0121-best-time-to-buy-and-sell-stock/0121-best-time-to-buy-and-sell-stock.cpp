class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int profit=0;
        for(int i=1;i<prices.size();i++){
            minprice=min(minprice,prices[i-1]);
            profit=max(profit,prices[i]-minprice);
        }     
        return profit;     
    }
};