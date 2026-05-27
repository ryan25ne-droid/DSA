class Solution {
public:
    void helper(vector<vector<int>>&adj, vector<bool>&visited, int src){
        visited[src]=true;
        for(auto& v: adj[src]){
            if(!visited[v]){
                helper(adj,visited,v);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj (n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;

        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                helper(adj,visited,i);
                count++;
            }
        }
        return count;        
    }
};