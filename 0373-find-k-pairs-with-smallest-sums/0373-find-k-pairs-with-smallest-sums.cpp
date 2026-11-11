// This is similar to merging k sorted lists. Instead of comparing every element with every element, we compare only  

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        vector<vector<int>> ans;
        using T= tuple<int, int, int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        int n= nums1.size();
        int m= nums2.size();

        for(int i= 0; i< min(n, k); i++){
            pq.push({nums1[i]+ nums2[0], i, 0});
        }

        while(k> 0 && !pq.empty()){
            k--;
            auto [sum, i, j]= pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});

            if(j+ 1< m){
                pq.push({nums1[i]+ nums2[j+ 1], i, j+ 1});
            }
        }

        return ans;
    }
};