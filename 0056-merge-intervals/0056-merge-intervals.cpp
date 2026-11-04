class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0]< b[0];
        });        

        vector<vector<int>> ans;

        int start= intervals[0][0];
        int end= intervals[0][1];

        for(int i= 0; i<n; i++){
            int low= intervals[i][0];
            int high= intervals[i][1];

            if(end< low || start> high){
                ans.push_back({start, end});
                start= low;
                end= high;
            }
            else{
                end= max(end, high);
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};