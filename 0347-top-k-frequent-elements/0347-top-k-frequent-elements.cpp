class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
// most frequent. Min- heap. Sort by frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int n= nums.size();

        unordered_map<int, int> freq;

        for(int x: nums){
            freq[x]++;
        }

// I earlier iterated over nums instead of freq. 2nd time we want each unique element to be pushed into  heap once
        for(auto& x: freq){ 
            pq.push({x.second, x.first});  //freq earlier so that heap orders by freq and not element value

            if(pq.size()> k){
                pq.pop();
            }
        }

        vector<int> ans(k);

        for(int i= 0; i< k; i++){
            ans[i]= pq.top().second;
            pq.pop();
        }

        return ans;      
    }
};