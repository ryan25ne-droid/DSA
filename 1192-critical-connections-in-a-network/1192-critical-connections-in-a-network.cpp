//Trajan's algorithm

class Solution{
private:
    int timer= 1;

public:
vector<int> tin;
vector<int> low;
vector<bool> vis;
vector<vector<int>> adj;
vector<vector<int>> bridges;
    
    void dfs(int node, int parent){
        vis[node]= true;
        tin[node]= low[node]= timer;
        timer++;

        for(auto& ele: adj[node]){
            if(ele== parent){
                continue;
            }
            else if(!vis[ele]){
                dfs(ele, node);
                low[node]= min(low[node], low[ele]);
// check for bridge condition
                
                if(low[ele] > tin[node]){
                    bridges.push_back({node, ele});
                }
            }
            else{  //we know this can't be a bridge for sure since we are visiting it for 2nd time. But we still care about lowest time
                low[node]= min(low[node], low[ele]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        adj.resize(n);
        tin.resize(n);
        vis.resize(n);
        vis.resize(n, false);
        low.resize(n);

        for(auto& ele: connections){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }

        // for(int i= 0; i< n; i++){
        //     if(!vis[i]){

        //     }
        // }

// We don't have to run multiple dfs assuming the network is a single component
        dfs(0, -1);
        return bridges;       
    }
};