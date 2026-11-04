class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n){
        vector<int> diff(n+ 2);   

        for(int i=0; i<bookings.size(); i++){
            int first= bookings[i][0];
            int last= bookings[i][1];
            int seats= bookings[i][2];

            diff[first]+= seats;      //corrosponding to lth flight
            diff[last+ 1]-= seats;        //corrosponding to rth flight
        }   

        vector<int> ans(n);  //1- indexed
        ans[0]= diff[1];

        for(int i= 1; i<n; i++){
            ans[i]= ans[i-1]+ diff[i+ 1];
        }

        return ans;
    }
};