class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();   
        int profit=0;
//greedy approach. Total profit is sum of all +ve profits achieved over time by selling as soon as you get a profit, then rebuying the stock on exact same day just in case
        for(int i=0;i<n-1;i++){
            if(prices[i]<prices[i+1]){
                profit+=prices[i+1]-prices[i];
            }
        } 
        return profit;                    
    }
};