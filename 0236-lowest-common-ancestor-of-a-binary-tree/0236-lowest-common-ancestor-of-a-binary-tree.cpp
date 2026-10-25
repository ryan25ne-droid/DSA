/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryLifting{
    static const int LOG= 18;
    unordered_map <TreeNode*, vector<TreeNode*>> up;
    unordered_map <TreeNode*, int> depth;

    void dfs(TreeNode* u, TreeNode* parent){
        up[u]= vector<TreeNode*>(LOG, nullptr);
        up[u][0]= parent;

        for(int j= 1; j<LOG; j++){
            TreeNode* mid= up[u][j-1]; 
            if(mid!= nullptr){
                up[u][j]= up[mid][j-1];  //2^j th ancestor of u is 2^(j-1)th ancestor of mid (which itself is 2^(j-1)th ancestor of u)
            }  
        }

        if(u->left!= nullptr){
            depth[u->left]= depth[u]+ 1;
            dfs(u->left, u);
        }  
        if(u-> right!= nullptr){
            depth[u->right]= depth[u]+ 1;
            dfs(u->right, u);
        }       
    }

public:
    void build(TreeNode* root){
        depth.clear();
        up.clear();

        depth[root]= 0;
        dfs(root, nullptr);
    }

    TreeNode* kthAncestor(TreeNode* u, int k){
        for(int j= 0; j< LOG && u; j++) {
            if(k & (1 << j)){
                u= up[u][j];
            }
        }
        return u;
    }

    TreeNode* lca(TreeNode* u, TreeNode* v){
        if(depth[u]< depth[v])
            swap(u, v);

        u= kthAncestor(u, depth[u] - depth[v]);

        if(u == v)
            return u;

        for(int j= LOG- 1; j>= 0; j--) {
            TreeNode* pu= up[u][j];
            TreeNode* pv= up[v][j];

            if(pu != pv) {
                u= pu;
                v= pv;
            }
        }
        return up[u][0];
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        BinaryLifting blft;
        blft.build(root);
        return blft.lca(p, q);        
    }
};