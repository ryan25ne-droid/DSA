class Solution {
public:
    int helper(int idx, int n, int left, vector<vector<int>>& events, vector<vector<int>> &dp){
        if(idx>= n){
            return 0;
        }
        if(left<= 0){
            return 0;
        }

        if(dp[idx][left]!= -1){
            return dp[idx][left];
        }
        
        int start= events[idx][0];
        int end= events[idx][1];
        int value= events[idx][2];

        int next= upper_bound(events.begin(), events.end(), end, [](int val, const vector<int> &a){
            return a[0]> val;
// note the inequality sign. Its reversed
        })- events.begin(); 

        int take= value+ helper(next, n, left-1, events, dp);
        int skip= helper(idx+1, n, left, events, dp);

        return dp[idx][left]= max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n= events.size();

        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0]!= b[0]){
                return a[0]< b[0];
            }
            return a[1]< b[1];
        });

        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        return helper(0, n, k, events, dp);        
    }
};