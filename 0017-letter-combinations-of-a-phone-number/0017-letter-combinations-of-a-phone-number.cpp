class Solution {
public:
    vector<string> mpp= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helper(string& digits, vector<string>& ans, string& temp, int idx, int n){
        if(idx== n){
            ans.push_back(temp);
            return;
        }

        int digit= digits[idx]- '0';

        for(char x: mpp[digit]){
            temp+= x;
            helper(digits, ans, temp, idx+ 1, n);
            temp.pop_back();
        }

        return;        
    }

    vector<string> letterCombinations(string digits){
        vector<string> ans;
        string temp= "";
        int n= digits.size();
        int idx= 0;

        helper(digits, ans, temp, idx, n);
        return ans;      
    }
};