class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges){
        vector<vector<pair<int,int>>> adj(n); 

//we code 0 for red and 1 for blue        
        for(auto& ele: redEdges){
            adj[ele[0]].push_back(make_pair(ele[1],0));
        } 
        for(auto& ele: blueEdges){
            adj[ele[0]].push_back(make_pair(ele[1],1));
        } 

        queue<tuple<int,int,int>>q;  //this tracks node, color, steps
        vector<int>ans(n,-1);
        vector<vector<bool>>visited(n,vector<bool>(2,false)); // [node][coloridx]
        ans[0]=0;
           
        q.push({0,-1,0}); //we don't mark self edge on 0 (if it exists) as either red or blue, otherwise that would limit the edges of a certain color

        while(!q.empty()){
            auto[u,prevcolor,steps]=q.front();
            q.pop();

            for(auto [v,color]: adj[u]){
                if(color!=prevcolor &&!visited[v][color]){
                    visited[v][color]=true;
                    
                    if(ans[v]==-1){ 
                        ans[v]=steps+1;
//if you have already visited an index previously, then visited it later in future with a shorter path is not possible. and since we only have to track the shortest path, we don't update the ans again  
                    }
                    q.push({v,color,steps+1});                   
                }
            }           
        } 
        return ans;     
    }
};