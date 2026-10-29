#define ll long long

struct BIT{
    vector<ll> bit;
    int n;
    BIT(int n): n(n), bit(n+1, 0) {}

    void update(int i, ll val){
        while(i<= n){
            bit[i]+= val;
            i+= (i& -i);
        }
    }

    ll prefix(int i){
        ll sum= 0;
        while(i>0){
            sum+= bit[i];
            i-= (i& -i);
        }
        return sum;
    }

    ll range(int l, int r){
        return prefix(r)- prefix(l- 1);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper){
        int ans= 0;
        int n= nums.size();

        vector<ll> prefix(n+ 1);
        prefix[0]= 0;

        for(int i= 0; i< n; i++){
            prefix[i+ 1]= prefix[i]+ (ll)nums[i];
        }

// coordinate compression
        vector<ll >vals;

        for(auto&p: prefix){
            vals.push_back(p- lower);
            vals.push_back(p);
            vals.push_back(p- upper);
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        unordered_map<int, int> compress;

        for(int i= 0; i<vals.size(); i++){
            compress[vals[i]]= i+ 1;   //BIT is 1-indexed
        }

        BIT bit(vals.size());

// insert prefix sum 0
        bit.update(compress[0], 1);

        for (int i= 1; i<= n; i++) {
            ll curr= prefix[i];

            int L= compress[curr- upper];
            int R= compress[curr- lower];

            ans += bit.range(L, R);

            bit.update(compress[curr], 1);
        }

        return ans;
    }
};

// Here, BIT isn't storing sums. It's storing frequency of previously seen prefix sums