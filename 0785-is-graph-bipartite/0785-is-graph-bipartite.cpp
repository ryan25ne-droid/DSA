class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph){
        int n= graph.size();
        vector<int> color(n, -1);
        queue<int> q;

        for(int i= 0; i<n; i++){
            if(color[i]!= -1){
                continue;
            }

            q.push(i);
            color[i]= 0;

            while(!q.empty()){
                int u= q.front();
                q.pop();

                for(int v: graph[u]){
                // not yet colored
                    if(color[v]== -1){
                        color[v]= !color[u];
                        q.push(v);
                    }
                    else if(color[v]== color[u]){
                        return false;
                    }
                }
            }
        }
        
        return true;                
    }
};