class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest){
        if(src==dest){
            return true;
        }

        vector<vector<int>> adj(n);

        for(auto&ele: edges){
            int u= ele[0];
            int v=ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(src);  //element from which traversal begins
        visited[src]=true;

        while(q.size()>0){
            int u=q.front();
            if(u==dest){
                return true;
            }
            q.pop();   //removes u form queue

            for(int v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        return false;        
    }
};