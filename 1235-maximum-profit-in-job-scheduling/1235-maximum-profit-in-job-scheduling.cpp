class Solution {
public:
    int helper(vector<vector<int>>& meeting, int idx, vector<int> &dp){
        if(idx>= meeting.size()){
            return 0;
        }

        if(dp[idx]!= -1){
            return dp[idx];
        }
        
        int start= meeting[idx][0];  
        int end= meeting[idx][1]; 
        int revenue= meeting[idx][2];

// skip current job
        int skip= helper(meeting, idx+1, dp);
    
//find earliest valid job
        int next = lower_bound(meeting.begin(), meeting.end(), end,[](const vector<int>& meet, int value){
            return meet[0] < value;
        }) -meeting.begin();
        
        int take= revenue+ helper(meeting, next, dp); 
        
        return dp[idx]= max(skip, take);        
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size();
        vector<vector<int>> meeting;
        
        for(int i=0; i<n; i++){
            meeting.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(meeting.begin(), meeting.end(), [](const vector<int> &a, const vector<int> &b){
            // if(a[0]!= b[0]){
            //     return a[0]<b[0];
            // }
            // return a[1]<b[1];   
            return a[0]< b[0];         
        });

        vector<int> dp(n, -1);
        
        return helper(meeting, 0, dp);
    }
};