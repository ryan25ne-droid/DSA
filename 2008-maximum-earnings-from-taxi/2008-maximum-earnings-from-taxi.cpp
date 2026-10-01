#define ll long long
class Solution {
public:
    ll helper(int idx, vector<vector<int>>& rides, int m, vector<ll> &dp){
        if(idx>= m){
            return 0;
        }

        if(dp[idx]!= -1){
            return dp[idx];
        }

        int start= rides[idx][0];
        int end= rides[idx][1];
        ll tip= rides[idx][2];

        int next= lower_bound(rides.begin(), rides.end(), end, [](const vector<int> &a, int val){
            return a[0]< val;
        })- rides.begin();

        ll take= end- start+ tip+ helper(next, rides, m, dp);
        ll skip= helper(idx+1, rides, m, dp);

        return dp[idx]= max(take, skip);
    }

    ll maxTaxiEarnings(int n, vector<vector<int>>& rides){
        int m= rides.size();
        vector<ll> dp(m, -1);

        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int> &b){
            if(a[0]!= b[0]){
                return a[0]< b[0];
            }
            return a[1]< b[1];
        });

        return helper(0, rides, m, dp);        
    }
};