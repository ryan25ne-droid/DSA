// Fenwick Tree
struct Fenwick{
    vector<int> arr;
    int n;
    Fenwick(int n) :n(n){
        arr.assign(n+ 1, 0);
    }

    void update(int idx, int val){
        for(; idx<= n; idx += (idx & -idx)){
            arr[idx] += val;
        }
    }

    int query(int idx){
        int sum= 0;
        for(; idx> 0; idx -= (idx & -idx)){
            sum += arr[idx];
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums){
        int n= nums.size();
//Coordinate compression on nums
        vector<int> sorted= nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    // the last line is for getting unique values from an array. Its a general trick remember it

    // Map each value to its compressed index
        unordered_map<int,int> compress;
        for(int i= 0; i< sorted.size(); i++){
            compress[sorted[i]]= i+ 1;
        }

    // Replace values in nums with compressed indices
        vector<int> compressed;
            for(int x: nums){
            compressed.push_back(compress[x]);
        }


        vector<int> counts(n);
        Fenwick fenwick(sorted.size());

    // Traverse from right to left
        for(int i= n-1; i>= 0; i--) {
            int idx= compress[nums[i]];
            counts[i]= fenwick.query(idx- 1); // count of smaller elements
            fenwick.update(idx, 1);             // add current element
        }

        return counts;        
    }
};