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
     void helper(int i, int j,int n, int m,vector<vector<char>>&board, vector<vector<bool>>&visited, Node*node, Trie&trie, vector<string>&ans, string& track){

        char c=board[i][j];
        
        if(node->children.count(c)==0){
            return;  //failed to find the word
        }
        node=node->children[c]; //move into child node;
        track+=c;
        visited[i][j]=true; 

        if(node->endOfword){
            ans.push_back(track);
            node->endOfword=false; //this is created specifically for this question.
            // return; By returning immediately, we stop exploring further neighbors. If the current word is a prefix of another longer word, we miss those longer words. So we don’t return after finding a word. Mark it as used and continue DFS.
        }

        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto&ele: dir){
            int nrow= i +ele[0];
            int ncol= j+ele[1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]){
                helper(nrow,ncol,n,m,board,visited,node,trie,ans,track);                   
            }             
        }
//backtracking starts
        track.pop_back();         
        visited[i][j]=false;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        int n=board.size();
        int m=board[0].size();

        vector<string>ans;
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        Trie trie;
        string track="";
        for(auto & word: words){
            trie.insert(word);
        }
        Node*temp=trie.root;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp->children.count(board[i][j])!=0){
                    helper(i,j,n,m,board,visited,temp,trie,ans,track);
                }
            }
        } 

        return ans;                       
    }
};