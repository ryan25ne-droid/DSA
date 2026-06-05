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
    void helper(TreeNode*root, stack<int>&st){
        if(root==nullptr){
            return;
        }
        st.push(root->val);
        helper(root->right, st);
        helper(root->left, st);
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int>ans;
        stack<int>st;

        helper(root,st);

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }        

        return ans;
    }
};