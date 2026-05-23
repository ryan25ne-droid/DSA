class Solution {
public:
    void helper(string &paren, vector<string>& ans, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(paren);
            return;
        }
        if (open > 0) {
            paren.push_back('(');
            helper(paren, ans, open-1, close+1);
            paren.pop_back();
        }
        if (close > 0) {
            paren.push_back(')');
            helper(paren, ans, open, close-1);
            paren.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string paren;
        helper(paren, ans, n, 0);
        return ans;
    }
};
