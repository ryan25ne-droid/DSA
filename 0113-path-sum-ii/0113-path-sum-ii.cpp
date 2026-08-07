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

    void helper(vector<vector<int>>& ans, TreeNode* root, int target, queue<int>q){
        if(root==nullptr){
            return;
        }

        if(root->left==nullptr && root->right==nullptr){
            if(target== root->val){
                vector<int> store;
                q.push(root->val);
                while(!q.empty()){
                    store.push_back(q.front());
                    q.pop();
                }
                ans.push_back(store);
            }
            else{
                q= queue<int>();
            }
            return;
        }

        q.push(root->val);

        helper(ans, root->left, target-root->val, q);
        helper(ans, root->right, target-root->val, q);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        vector<vector<int>> ans;
        queue<int> q;
        helper(ans, root, targetSum, q);
        return ans;                
    }
};