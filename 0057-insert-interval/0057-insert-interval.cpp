class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n= intervals.size();
        bool inserted= false;

        if(n== 0){
            return {newInterval};
        }
        if(newInterval.size()== 0){
            return intervals;
        }

        int start= newInterval[0];
        int end= newInterval[1];

        vector<vector<int>> ans;

        for(int i= 0; i<n; i++){
            int low= intervals[i][0];
            int high= intervals[i][1];

            if(high< start){
                ans.push_back({low, high});
            }
            else if(end< low){
                if(!inserted){
                    ans.push_back({start, end});
                    inserted= true;
                }
                ans.push_back({low, high});
            }

            else{
                start= min(start, low);
                end= max(end, high);
            }
        }

        if(!inserted){
            ans.push_back({start, end});
        }

        return ans;
    }
};