//A cycle in the prerequisite graph means there’s a circular dependency.
// Example:
// Course A requires Course B. Course B requires Course C. Course C requires Course A.

// This loop makes it impossible to start — no course in the cycle can ever be taken first.

class Solution {
public:
//helper returns true if no cycle exists
    bool helper(int src, vector<bool>&visited, vector<bool>&recStack,vector<vector<int>>&adj){
        
//this check is redundant. DFS already handles nodes with no outgoing edges
        // if(adj[src].empty() && !recStack[src]){
        //     return true;
        // }

//depending on whether we check a node in recStack in the function call for the node itself or before the function call (in the call of the neighbours of its parent node) there are two sloightly different (but both corrrect) versions of the code. I check the recStack in the call for the node itself. although its less standard. but correct

        if(recStack[src]){
            return false;
        }

        if(!visited[src]){
            visited[src]=true;
            recStack[src]=true;
            for(auto& v:adj[src]){
                if(!helper(v,visited,recStack,adj)){
                    return false;
                }
            }
            recStack[src]=false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        int V= numCourses;
        vector<vector<int>>adj(V);
        for(auto &ele :prerequisites){  //edge from u to v
            int u= ele[1];
            int v= ele[0];
            adj[u].push_back(v);           
        }  

        vector<bool>visited(V,false);
        vector<bool>recStack(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(!helper(i,visited,recStack,adj)){
                    return false;
                }
            } 
        }
        return true;        
    }
};