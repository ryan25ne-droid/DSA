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
    bool singleNodeValid(TreeNode*root, TreeNode* max, TreeNode* min){
        if(root==nullptr){ 
            return true;
        }
        if(min!=nullptr &&root->val<=min->val){
            return false;
        }
        else if(max!=nullptr &&root->val>=max->val){
            return false;
        }
        return singleNodeValid(root->left,root,min)&&singleNodeValid(root->right,max,root);
    }
    bool isValidBST(TreeNode* root) {
       return singleNodeValid(root,nullptr,nullptr);      
    }
};