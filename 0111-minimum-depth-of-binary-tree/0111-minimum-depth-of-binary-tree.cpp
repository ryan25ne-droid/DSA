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
    int minDepth(TreeNode* root) {
        if(root== nullptr){
            return 0;
        }     

        queue<pair<TreeNode*, int>> q; 
        q.push({root, 1});

        while(!q.empty()){
            auto[root, level]= q.front();
            q.pop();

            if(root->left== nullptr && root->right== nullptr){
                return level;
            }  
            if(root->left != nullptr){
                q.push({root->left, level+1});
            }
            if(root->right!= nullptr){
                q.push({root->right, level+1});
            }      
        }
        return -1;
    }
};