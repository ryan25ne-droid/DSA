/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root== nullptr || root== p || root== q){
            return root;
        }

        TreeNode* left= lca(root->left, p, q);
        TreeNode* right= lca(root->right, p, q);

        if(left && right){
            return root;
        }

        return left? left: right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root== nullptr){
            return root;
        }

        unordered_map <TreeNode*, int> depth;
        queue <pair<TreeNode*, int>> q; 
        int maxDepth= 0;

        q.push({root, 0});
        while(!q.empty()){
            auto [node, d]= q.front();
            q.pop();

            depth[node]= d;
            maxDepth= max(maxDepth, d);

            if(node->left!= nullptr){
                q.push({node->left, d+1});
            }
            if(node->right!= nullptr){
                q.push({node->right, d+1});
            }
        }

        TreeNode* u= nullptr;

        for(auto& e: depth){
            if(e.second== maxDepth){
                u= lca(root, u, e.first);
            }
        }
        return u;
    }
};