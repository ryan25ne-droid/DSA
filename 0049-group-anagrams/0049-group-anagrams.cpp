class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(string s :strs){
            string key =s;
            sort(key.begin(), key.end()); // signature
            mpp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto &entry :mpp){
            ans.push_back(entry.second);
        }
        return ans;
    }
};
