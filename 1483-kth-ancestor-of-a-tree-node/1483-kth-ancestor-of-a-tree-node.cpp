class TreeAncestor {
    vector<vector<int>> up;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent){
        LOG= ceil(log2(n))+ 1;
        up.resize(n+1, vector<int>(LOG, -1));

        for(int i=0 ;i<n; i++){
            up[i][0]= parent[i];
        }      

        for(int j= 1; j< LOG; j++){
            for(int i= 0; i< n; i++){
                int mid= up[i][j -1];

                if(mid!= -1){
                    up[i][j]= up[mid][j -1];
                }
                else{
                    up[i][j]= -1;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k){
        int ans= node;
        for(int i= 0; i< LOG; i++){
            if(k & (1<< i)){
                ans= up[ans][i];
            }

            if(ans== -1){
                return -1;
            }
        }
        return ans;        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */