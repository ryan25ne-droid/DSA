class NumArray {
    int n;
    vector<int> heap;

    void build(const vector<int> &a, int node, int l, int r){
        if(l== r){
            heap[node]= a[l];
            return;
        }
        int m= (l+ r)/2;
        build(a, 2* node, l, m);
        build(a, 2* node + 1, m + 1, r);
        heap[node]= heap[2 *node] + heap[2* node + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l== r){
            heap[node] = val;
            return;
        }

        int m= (l+r)/ 2;
        if(idx <= m){
            update(2* node, l, m, idx, val);
        }
        else{
            update(2* node + 1, m + 1, r, idx, val);
        }

        heap[node]= heap[2* node]+ heap[2* node +1];
    }

    int qry(int node, int l, int r, int ql, int qr) {
        if(qr <l || r< ql){
            return 0;        // disjoint 
        }          
        if(ql<= l && r<= qr){
            return heap[node];       // fully inside
        }

        int m= (l+ r)/ 2;
        return qry(2* node, l, m, ql, qr)+ qry(2* node+ 1, m+1, r, ql, qr);   // partial
    }

public:
    NumArray(vector<int>& nums) : n(nums.size()), heap(4 * nums.size()){
        build(nums, 1, 0, n - 1);
    }
    
    void update(int idx, int val){
        update(1, 0, n - 1, idx, val);        
    }
    
    int sumRange(int l, int r){
        return qry(1, 0, n- 1, l, r);        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */