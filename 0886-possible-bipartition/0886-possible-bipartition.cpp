class Solution {
public:
    bool helper(int src, vector<vector<int>>&adj, vector<int>&color){
        queue<int>q;
        q.push(src);
        color[src]=1;
        
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto& v: adj[u]){
                if(color[v]==0){
                    q.push(v);
                    color[v]=-color[u];  //opposite of the parent
                }
                else if(color[u]==color[v]){  //both have same colors
                    return false;
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);  //the people are labelledd from 1 to n. 1 based indexing
        for(auto &ele: dislikes){
            int u= ele[0];
            int v= ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }  
        vector<int>color (n+1,0);  //0 means not visited. 1 means color red. -1 means color blue.
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                if(!helper(i,adj,color)){
                    return false;
                }
            }
        }
        return true;      
    }
};