class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size()) return {};
        
        unordered_set<string> dict;

        for(int i=0; i<wordList.size(); i++){
            dict.insert(wordList[i]);
        }

        if(!dict.count(endWord)){
            return {};
        }

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> dist;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front(); q.pop();
            int d = dist[word];
            for (int i=0; i<word.size(); i++) {
                string temp = word;
                for (char c='a'; c<='z'; c++) {
                    temp[i] = c;
                    if (dict.count(temp)) {
                        if (!dist.count(temp)) {
                            dist[temp] = d+1;
                            q.push(temp);
                        }
                        if (dist[temp] == d+1) {
                            parents[temp].push_back(word);
                        }
                    }
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        function<void(string)> dfs = [&](string word) {
            path.push_back(word);
            if (word == beginWord) {
                vector<string> ladder(path.rbegin(), path.rend());
                res.push_back(ladder);
            } 
            else {
                for (auto &p : parents[word]) dfs(p);
            }
            path.pop_back();
        };

        if (dist.count(endWord)) dfs(endWord);
        return res;
    
    }
};