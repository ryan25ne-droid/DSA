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
    pair<TreeNode*, int> dfs(TreeNode* root){   //this depth is not the depth of the LCA< but the depth of the subtree containing LCA
        if(root== nullptr){
            return {nullptr, 0};
        }

        auto [left, dl]= dfs(root->left);
        auto [right, dr]= dfs(root->right);

        if(dl== dr){
            return {root, dl+1};
        }
        if(dl> dr){
            return {left, dl+ 1};
        }

        return {right, dr+ 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root){
        auto [node, depth]= dfs(root);
        return node;        
    }
};