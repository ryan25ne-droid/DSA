//topological sorting
class Solution {
public:
    bool helper(int src, vector<bool>&visited, vector<vector<int>>&adj,vector<bool>&recStack, stack<int>&s){
        if(recStack[src]){  //cycle detected. Not a DAG, no topological order exists. Instead of emptying the stack, we use a boolean variable to signify that we don't have to read the stack at all now since topological order doesn't exist.
            return false;
        }

        if(!visited[src]){
            visited[src]=true;
            recStack[src]=true;

            for(auto&ele: adj[src]){
                if(!helper(ele,visited,adj,recStack,s)){
                    return false;
                }
            }
            recStack[src]=false;
            s.push(src);
        }
        return true;       
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        int n=numCourses;

        vector<vector<int>>adj(n);
        for(auto& ele :prerequisites){
            int u=ele[0];
            int v=ele[1];
            adj[v].push_back(u); 
        }
        
        stack<int> s;
        vector<bool>visited(n,false);
        vector<bool>recStack(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(!helper(i,visited,adj,recStack,s)){
                    return {}; 
 //if cycle exists. Not a DAG, no topological order exists. We don't have to read the stack at all now since topological order doesn't exist.
                }
            }
        }

        vector<int>ans;

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;        
    }
};