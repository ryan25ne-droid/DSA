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
    vector<int> helper(TreeNode* root){
        if(root== nullptr){
            return {0,0};
        }        
        vector<int> left= helper(root->left);
        vector<int> right= helper(root->right);

        int height= 1+ max(left[0], right[0]);
        int diam= max(left[0]+ right[0], max(left[1], right[1]));

        return {height, diam};
    }

    int diameterOfBinaryTree(TreeNode* root){
        if(root== nullptr){
            return 0;
        }
        
        return helper(root)[1];   
    }
};