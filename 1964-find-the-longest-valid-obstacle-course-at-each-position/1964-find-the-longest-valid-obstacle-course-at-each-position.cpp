class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles){
        int n= obstacles.size();
        vector<int> ans(n);   // dp[i] is same as ans[i]

        ans[0]= 1; 

        vector<int> temp;
        temp.push_back(obstacles[0]);   

        for(int i= 1; i<n; i++){
            if(obstacles[i]>= temp.back()){
// notice that here non decreasing works instead of increasing
                temp.push_back(obstacles[i]);
                ans[i]= temp.size();
            }
            else{
                int idx= upper_bound(temp.begin(), temp.end(), obstacles[i])- temp.begin();
                temp[idx]= obstacles[i];
                // ans[i]=  temp.size(); this gives length of LIS ending somewhere before i, not necessarily at i.
                ans[i]= 1+ idx;
            }

        }       

        return ans;
    }
};

// longest increasing subsequence. Just the catch is that tabulation DP gives TLE due to O(n^2) T.C.

// lower_bound(x)- Finds the first element ≥ x
// upper_bound(x)- Finds the first element > x

// Here the concern that we need the current subsequence to include the current element for each ans[i] is already dealt with using upper_bound