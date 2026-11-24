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
// returns <take, skip>
    pair<int, int> dfs(TreeNode* root){
        if(root== nullptr){
            return {0, 0};
        }

        auto left= dfs(root->left);
        auto right= dfs(root->right);

        int take= (root-> val)+ left.second+ right.second;
        int skip= max(left.first, left.second)+ max(right.first, right.second);

        return {take, skip};
    }

    int rob(TreeNode* root) {
        // dp[u] represetns the max possible profit in robbing the subtree rooted at u.
// then dp[u]= max(u-> val+ dp[u->left->left]+ dp[u->left->right]+ dp[u->right->left]+ dp[u->right-> left], dp[u->left]+ dp[u->right]);
        
// but vector<TreeNode*> dp is almost never used. Most easy is to use a dfs which returns all the dp states needed. 
        
// take[u]= max(u-> val+ skip[u-> left], skip[u-> right])
// skip[u]= take[u->left], take[u-> right]
        auto ans= dfs(root);
        return max(ans.first, ans.second);        
    }
};