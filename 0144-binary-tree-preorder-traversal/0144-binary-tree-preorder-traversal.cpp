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
    void helper(stack<int>&st, TreeNode*root){
        if(root==nullptr){
            return;
        }

        helper(st,root->right);
        helper(st,root->left);
        st.push(root->val);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int>ans;
        stack<int>st;
        
        helper(st,root);

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }    
        return ans;            
    }
};