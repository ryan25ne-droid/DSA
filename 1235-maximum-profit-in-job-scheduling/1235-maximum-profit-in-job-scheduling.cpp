class Solution {
public:
    int helper(vector<vector<int>>& meetings, int idx, vector<int> &dp){
        if(idx>= meetings.size()){
            return 0;
        }

        if(dp[idx]!= -1){
            return dp[idx];
        }
        
        int start= meetings[idx][0];  
        int end= meetings[idx][1]; 
        int revenue= meetings[idx][2];

// skip current job
        int skip= helper(meetings, idx+1, dp);
    
//find earliest valid job
        int next = lower_bound(meetings.begin(), meetings.end(), end,[](const vector<int>& meeting, int value){
            return meeting[0] < value;
        }) -meetings.begin();
        
        int take = revenue + helper(meetings, next, dp); 
        
        return dp[idx]= max(skip, take);        
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size();
        vector<vector<int>> meetings;
        
        for(int i=0; i<n; i++){
            meetings.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b){
            // if(a[0]!= b[0]){
            //     return a[0]<b[0];
            // }
            // return a[1]<b[1];   
            return a[0]< b[0];         
        });

        vector<int> dp(n, -1);
        
        return helper(meetings, 0, dp);
    }
};