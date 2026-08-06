class Solution {
public:
    vector<string> map={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helper(string digits, vector<string>&ans, int idx, string &comb){
        if(idx>= digits.size()){
            ans.push_back(comb);
            return;
        }

        int val= digits[idx]-'0';
        
        for(auto& letter: map[val]){ 
            comb.push_back(letter);
            helper(digits, ans, idx+1, comb);
            comb.pop_back();
        }        
    }

    vector<string> letterCombinations(string digits){
        vector<string> ans;
        string comb= "";
        int n= digits.size();

        helper(digits, ans, 0, comb);
        return ans;      
    }
};