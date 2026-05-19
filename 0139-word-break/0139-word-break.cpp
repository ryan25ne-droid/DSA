class Node{
public:
    unordered_map<char,Node*> children;
    bool endOfword;
    Node(){
        endOfword=false;
    }
};

class Trie{
    Node*root;
public:
    Trie(){
        root= new Node();
    }
    void insert(string key){
        Node*temp=root; //used for tracking Level-Wise-Letter-Wise traversal.

        for(int i=0;i<key.size();i++){ //O(L)
//if the children of a node already has a character then do nothing. Otherwise
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endOfword=true;
    }

    bool search(string key){
        Node*temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                return false;
            }
            temp=temp->children[key[i]];
        }
        return temp->endOfword; //if this word doesn't exist, endOfword returns false.
    //Don't returnn true directly
    }
};

class Solution {
public:
    bool helper2(Trie& trie, string str, unordered_map<string,int>& dp) {
        if (str.empty()) return true;

        if (dp.count(str)) return dp[str]; // memoized result

        int n = str.size();
        for (int i = 0; i < n; i++) {
            string prefix = str.substr(0, i+1);
            string suffix = str.substr(i+1);

            if (trie.search(prefix) && helper2(trie, suffix, dp)) {
                return dp[str] = true;
            }
        }
        return dp[str] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (string &ele : wordDict) {
            trie.insert(ele);
        }
        unordered_map<string,int> dp;
        return helper2(trie, s, dp);
    }
};
