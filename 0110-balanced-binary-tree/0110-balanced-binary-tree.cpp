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

    int helper(TreeNode* root, bool &flag){
        if(root== nullptr){
            return 0;
        }
        int leftHeight= helper(root->left, flag);
        int rightHeight= helper(root->right, flag);

        if(abs(leftHeight- rightHeight) > 1){
            flag= false;
        }

        return 1+ max(leftHeight, rightHeight);        
    }

    bool isBalanced(TreeNode* root) {
        if(root== nullptr){
            return true;
        }
        bool flag= true;

        int u= helper(root, flag);

        return flag;        
    }
};