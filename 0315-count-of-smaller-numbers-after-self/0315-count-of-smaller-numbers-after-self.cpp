// Fenwick Tree
#define ll long long
struct BIT{
    int n;
    vector<ll> bit;

    BIT(int n): n(n), bit(n+1, 0){}

    void update(int i, ll val){
        while(i<= n){
            bit[i]+= val;
            i+= (i& -i);  //updating means i+= lowbit(i)
        }
    }

    ll prefix(int i){
        ll sum= 0;
        while(i> 0){
            sum+= bit[i];
            i-= (i& -i);   //i-= lowbit(i)
        }
        return sum;
    }

    ll range(int l, int r){
        return prefix(r)- prefix(l-1);
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
        // vector<int> compressed;
        //     for(int x: nums){
        //     compressed.push_back(compress[x]);
        // }

        vector<int> counts(n);
        BIT bt (sorted.size());

    // Traverse from right to left
        for(int i= n-1; i>= 0; i--) {
            int idx= compress[nums[i]];
            counts[i]= bt.prefix(idx- 1); // count of smaller elements
            bt.update(idx, 1);             // add current element
        }

        return counts;        
    }
};