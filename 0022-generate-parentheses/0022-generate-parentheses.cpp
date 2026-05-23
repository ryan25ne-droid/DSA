class Solution {
public:
    void helper(string &paren, vector<string>& ans, int i, int j) {
        // Base case: no opens left and no unmatched opens
        if (i == 0 && j == 0) {
            ans.push_back(paren);
            return;
        }

        // If we still have opens left, place '('
        if (i > 0) {
            paren.push_back('(');
            helper(paren, ans, i-1, j+1);  // one less open, one more unmatched
            paren.pop_back();
        }

        // If we have unmatched opens, we can place ')'
        if (j > 0) {
            paren.push_back(')');
            helper(paren, ans, i, j-1);    // same opens, one less unmatched
            paren.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string paren;
        helper(paren, ans, n, 0);  // start with n opens, 0 unmatched
        return ans;
    }
};

