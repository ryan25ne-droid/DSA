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
    bool isLeaf(TreeNode*root){
        if(root!=nullptr && root->left==nullptr && root->right==nullptr){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if(targetSum<0){
        //     return false;
        // }
        //Above statement can reject valid paths if -ve values exist in the tree.
        if(root==nullptr){
            return false; //this deals with the empty tree case
        }
        if(targetSum!=root->val && isLeaf(root)){
            return false;
        }
        if (targetSum==root->val && isLeaf(root)){
            return true;
        }

        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);        
    }
};