class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n){
        vector<int> diff(n+ 1);   

        for(int i=0; i<bookings.size(); i++){  //converting 1-indexed to 0- indexed
            int l= bookings[i][0]- 1;
            int r= bookings[i][1]- 1;
            int seats= bookings[i][2];

            diff[l]+= seats;      //corrosponding to lth flight
            diff[r+ 1]-= seats;        //corrosponding to rth flight
        }   

        vector<int> ans(n);  //0- indexed
        ans[0]= diff[0];

        for(int i= 1; i<n; i++){
            ans[i]= ans[i-1]+ diff[i];
        }

        return ans;
    }
};