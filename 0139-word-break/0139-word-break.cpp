static auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
    }();

class Node{
public:
    unordered_map<char,Node*> children;
    bool endOfword;
    Node(){
        endOfword=false;
    }
};

class Trie{
public:
    Node*root;
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
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (string &ele : wordDict){
            trie.insert(ele);
        }

        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            if (!dp[i]){
                continue;
            }
            Node* node = trie.root;
            for (int j = i;j < n; j++) {
                if (node->children.count(s[j]) == 0){
                    break;
                }
                node = node->children[s[j]];
                if (node->endOfword){
                    dp[j+1] = true;
                }
                if(dp[n]==true){
                    return dp[n];  //early exit
                }
            }
        }
        return dp[n];
    }
};
