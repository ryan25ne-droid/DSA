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
    int ans= 0;
   // dir 0 means we came from left, 1 for right 
    pair<int, int> helper(TreeNode* root){
        if(root== nullptr){
            return {-1, -1};
        }

        auto L= helper(root-> left);
        auto R= helper(root-> right);

        int leftPath= L.second + 1;  //second because to find the leftPath of current node, we need length of rightPath of the left subtree.
        int rightPath= R.first+ 1;

        ans= max(ans, max(leftPath, rightPath));

        return {leftPath, rightPath};       
    }

    int longestZigZag(TreeNode* root) {
// helper returns max possible path starting from the current node in left, right direction. And ans tracks this for every node. Because the longest path can start from anywhere, not necessarily the root

        helper(root);
        return ans;            
    }
};