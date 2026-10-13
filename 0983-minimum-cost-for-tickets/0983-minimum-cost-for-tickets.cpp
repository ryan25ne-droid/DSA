class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs){
        int n= days.size();
        int cost0= costs[0];
        int cost7= costs[1];
        int cost30= costs[2];

        vector<int> dp(n+1, 0);

        for(int i= 1; i<=n; i++){
            int currDay= days[i-1];
            int ans1= cost0+ dp[i-1];

            int idx7= upper_bound(days.begin(), days.end(), currDay-7)- days.begin();
            
            int ans2= cost7+ dp[idx7];

            int idx30= upper_bound(days.begin(), days.end(), currDay-30)- days.begin();

            int ans3= cost30+ dp[idx30];
            dp[i]= min(ans1, min(ans2, ans3));
        }

        return dp[n];                        
    }
};