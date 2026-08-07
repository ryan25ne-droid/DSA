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

    void helper(vector<vector<int>>& ans, TreeNode* root, int target, vector<int>&path){
        if(root==nullptr){
            return;
        }

        if(root->left==nullptr && root->right==nullptr){
            if(target== root->val){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(root->val);

        helper(ans, root->left, target-root->val, path);
        helper(ans, root->right, target-root->val, path);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        vector<vector<int>> ans;
        vector<int> path;
        helper(ans, root, targetSum, path);
        return ans;                
    }
};