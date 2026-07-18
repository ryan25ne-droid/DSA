class TreeAncestor {
public:
    vector<vector<int>>up;
//up[i][j] stores 2^j th ancestor of node i
    int LOG;
    TreeAncestor(int n, vector<int>& parent){
        LOG= ceil(log2(n))+1;
        up.assign(n, vector<int>(LOG, -1));  //log2(n) is log to the base 2

        for(int i=0; i<n; i++){
            up[i][0]= parent[i];
        }

        for(int j=1; j<LOG; j++){
            for(int i=0; i<n; i++){
                if(up[i][j-1]!= -1){
                    up[i][j]= up[up[i][j-1]][j-1];
                }
// because 2^j= 2*(j-1)+ 2*(j-1) 
            }
        }
    }
    
    int getKthAncestor(int node, int k){
        //we need to find j1, j2, j3 such that j1+ j2+ j3... =k. break the path of size k into powers of 2.  
        int anc=node;

        for (int count=0; count<32; count++) {
            if (k & (1 <<count)){   // check if kth bit is set
                anc= up[anc][count];
                if(anc==-1){
                    return -1;
                }                
            }
        }
        return anc;     
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */