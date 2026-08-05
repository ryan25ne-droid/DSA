class Solution {
public:
    void DFS(vector<vector<int>> &adj, vector<bool>& visited, int k){
        if(visited[k]){
            return;
        }

        visited[k]= true;
        for(auto& u: adj[k]){
            DFS(adj, visited, u);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations){
        
        vector<vector<int>> adj(n);

        vector<int> complete(n);

        for(int i=0; i<n; i++){
            complete[i]= i;
        }

        for(auto& ele: invocations){
            int u= ele[0];
            int v= ele[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(n, false);

        DFS(adj, visited, k);

        for(int i=0; i<n; i++){
            if(adj[i].empty()){
                continue;
            }
            for(auto & v: adj[i]){
                if(!visited[i] && visited[v]){
                    return complete;
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }

        return ans;               
    }
};