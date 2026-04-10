class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfword;
    Node(){
        endOfword=false;
    }
};
class Trie{
public:
    Node*root;
    Trie(){
        root=new Node();
    }
    void insert(string key){
        Node*temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node;
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
        return temp->endOfword;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        Trie trie;
        for(auto ele:strs){
            trie.insert(ele);
        }
        // string key=strs[0];
        // Node*temp=trie.root;
        // int i=0;
        // while(temp->children.size()==1 &&temp->endOfword!=true){
        //     temp=temp->children[key[i]];
        //     ans+=key[i];
        //     i++;
        // }
//this is correct but there is other way
        Node*temp=trie.root;
        while(temp->children.size()==1 && temp->endOfword!=true){
            ans+=temp->children.begin()->first;
            temp=temp->children.begin()->second;
        //temp->chiildren.begin() returns the first element of map. and since map has only one element...
        }

        return ans;
    }
};