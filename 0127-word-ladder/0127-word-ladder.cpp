class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(beginWord.size()!= endWord.size())  return 0;
        queue<pair<string,int>> q;

        unordered_set<string> dict;
        for(int i=0; i<wordList.size(); i++){
            dict.insert(wordList[i]);
        }

        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word,steps]= q.front();
            q.pop();

            if(word== endWord){
                return steps;
            }

            for(int i=0; i<word.size(); i++){
                char original= word[i];
                for(int j=0; j<26; j++){
                    word[i]= 'a'+ j;
                    if (dict.count(word)){
                        q.push({word, steps+1});
                        dict.erase(word);
                    }
                }
                word[i]= original; 
            }
        }
        return 0;        
    }
};

// A priority queue is useful in weighted shortest‑path problems (like Dijkstra). Here every transformation (changing one letter) has equal cost (1 step).

// Since all edges are unweighted, a simple FIFO queue is enough.