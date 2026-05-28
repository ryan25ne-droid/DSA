class Solution {
public:
    void helper(int src, int dest, vector<bool>&visited, vector<vector<int>>&adj,vector<vector<int>>&ans, vector<int>&path){
        if(src==dest){
            ans.push_back(path);
            return;
        } 
        for(auto &ele: adj[src]){
            if(!visited[ele]){
                path.push_back(ele);
                visited[ele]=true;
                helper(ele,dest,visited,adj,ans,path);
                visited[ele]=false;
                path.pop_back();
            }
        } 
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj){
        int n=adj.size();

        vector<bool>visited(n,false);
        vector<int>path;
        path.push_back(0);
        vector<vector<int>>ans;

        helper(0,n-1,visited,adj,ans,path);
        return ans;        
    }
};