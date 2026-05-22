class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> next(5,0);  //keeps track of the best profits upto the
// next day. Cause we only need to know the payoffs upto the immediate next day(which accounts all the other forward days payoffs) to decide the current day payoff.

        vector<int> curr(5,0);

        for(int i=n-1; i>=0; i--){
            curr[4]= max(next[4], next[3]-prices[i]); // second buy
            curr[3]= max(next[3], next[2]+prices[i]); // first sell
            curr[2]= max(next[2], next[1]-prices[i]); // first buy
            curr[1]= max(next[1], next[0]+prices[i]); // second sell
            curr[0]= 0; // no transactions
            next= curr;
        }

        return next[4]; // max profit after at most 2 transactions
    }
};
