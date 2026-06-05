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
    Node* root;
    Trie(){
        root= new Node();
    }

    void insert(string s){
        Node*temp=root;

        for(int i=0;i<s.size();i++){
            if(temp->children.count(s[i])==0){
                temp->children[s[i]]= new Node();
            }
            temp=temp->children[s[i]];
        }
        temp->endOfword=true;
    }
};

class Solution {
public:
     void helper(int i, int j,vector<vector<char>>&board, Node*node, vector<string>&ans, string& track){

        char c=board[i][j];
        
        if(node->children.count(c)==0){
            return;  //failed to find the word
        }
        node=node->children[c]; //move into child node;
        track.push_back(c);
        board[i][j]='#';  //optimisation for visited boolean array

        if(node->endOfword){
            ans.push_back(track);
            node->endOfword=false; //this is created specifically for this question.
            // return; By returning immediately, we stop exploring further neighbors. If the current word is a prefix of another longer word, we miss those longer words. So we don’t return after finding a word. Mark it as used and continue DFS.
        }

        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto&ele: dir){
            int nrow= i +ele[0];
            int ncol= j+ele[1];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && board[nrow][ncol]!='#'){
                helper(nrow,ncol,board,node,ans,track);                   
            }             
        }
//backtracking starts
        track.pop_back();         
        board[i][j]=c;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){

        vector<string>ans;

        Trie trie;
        string track="";
        for(auto & word: words){
            trie.insert(word);
        }
        Node*temp=trie.root;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(temp->children.count(board[i][j])!=0){
                    helper(i,j,board,temp,ans,track);
                }
            }
        } 
        return ans;                       
    }
};