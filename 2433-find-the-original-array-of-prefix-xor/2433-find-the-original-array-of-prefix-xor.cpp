class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n= pref.size();
        vector<int> arr(n);

        arr[0]= pref[0];

        for(int i= 0; i<n-1; i++){
            arr[i+1]= pref[i]^ pref[i+1];
        }

        return arr;        
    }
};