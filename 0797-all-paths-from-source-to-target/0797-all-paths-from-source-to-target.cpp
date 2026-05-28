//We don't need visited array here at all.
//In problems like “all paths in an undirected graph,” revisiting nodes can cause cycles and duplicate paths.

// So we use visited to prevent revisiting. But here the graph is a DAG. There are no cycles. Every path eventually terminates at n‑1.

// Using visited here is redundant

class Solution {
public:
    void helper(int src, int dest, vector<vector<int>>&adj,vector<vector<int>>&ans, vector<int>&path){
        path.push_back(src);
        if(src==dest){
            ans.push_back(path);
            return;
        } 
        for(auto &ele: adj[src]){
            helper(ele,dest,adj,ans,path);
            path.pop_back();
        } 
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int>path;
        vector<vector<int>>ans;

        helper(0,n-1,adj,ans,path);
        return ans;        
    }
};