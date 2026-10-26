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
    TreeNode* lca(TreeNode* root, int left, int right){
        if(root== nullptr){
            return nullptr;
        }
        if(root->val== left || root->val== right){
            return root;
        }
        TreeNode* Lnode= lca(root->left, left, right);
        TreeNode* Rnode= lca(root->right, left, right);

        if(Lnode!= nullptr && Rnode!= nullptr){
            return root;
        }
        if(Lnode!= nullptr){
            return Lnode;
        }
        return Rnode;
    }

// the problem is that in case of dealing with only integers, how do I recurse the tree? I need pointers. So lca should return TreeNode*, not int.

    bool getStr(TreeNode* parent, int child, string& ans){
        if(parent== nullptr){
            return false;
        }
        if(parent->val == child){
            return true;
        }

        ans+= 'L';
        if(getStr(parent->left, child, ans)){ // we found the child
            return true;
        }  
        ans.pop_back();

        ans+= 'R';
        if(getStr(parent->right, child, ans)){
            return true;
        }
        ans.pop_back();

        return false; 
    }

    string getDirections(TreeNode* root, int startVal, int destVal){
        TreeNode* L= lca(root, startVal, destVal);
        string str1= "";
        string str2= "";

        getStr(L, startVal, str1);
        getStr(L, destVal, str2);

        int n= str1.size();
        str1= string(n, 'U');       

        return str1+ str2;         
    }
};