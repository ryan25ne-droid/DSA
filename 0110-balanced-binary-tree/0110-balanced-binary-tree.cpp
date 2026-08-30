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

    int helper(unordered_map<TreeNode*, int>& mpp, TreeNode* root){
        if(root== nullptr){
            return 0;
        }
        int leftHeight= helper(mpp, root->left);
        int rightHeight= helper(mpp, root->right);

        if(abs(leftHeight- rightHeight) > 1){
            mpp[root]= -1;
            return max(leftHeight, rightHeight)+ 1;
        }

        return mpp[root]= 1+ max(leftHeight, rightHeight);        
    }

    bool isBalanced(TreeNode* root) {
        if(root== nullptr){
            return true;
        }

        unordered_map<TreeNode*, int> mpp;

        int u= helper(mpp, root);

        for(auto& ele: mpp){
            if(ele.second== -1){
                return false;
            }
        }

        return true;        
    }
};