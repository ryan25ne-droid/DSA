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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root== nullptr){
            return ans;
        }

        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        int prevLvl= 0;

        vector<int> trav;

        while(!q.empty()){
            auto[root, level] = q.front();
            q.pop();

            if(root== nullptr){
                continue;
            }

            int u= root->val;

            if(level > prevLvl){
                ans.push_back(trav);
                trav.clear();
                prevLvl= level;
            }
            trav.push_back(u);
            q.push({root->left, level+1});
            q.push({root->right, level+1});
        }
        ans.push_back(trav);
        return ans;        
    }
};