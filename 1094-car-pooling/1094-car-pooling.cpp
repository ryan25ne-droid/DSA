class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n= trips.size();
        vector<int> diff(1001, 0);

        for(int i= 0; i<n; i++){
            int points= trips[i][0];
            int start= trips[i][1];
            int end= trips[i][2];

            diff[start]+= points;
            diff[end]-= points;
        }

        bool possible= true;
        int occupancy= 0;

        for(int i= 0; i<= 1000; i++){
            occupancy+= diff[i];
            if(occupancy> capacity){
                possible= false;
                break;
            }
        }

        return possible;      
    }
};