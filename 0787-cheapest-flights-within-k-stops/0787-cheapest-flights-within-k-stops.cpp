//bellman's Algo. Normal Bellman algo needs us to set an outer loop running n-1 times (n is no of vertices) and an inner loop traversing over all the edges. 
//We don’t need an extra loop over vertices or over stops inside the edge loop. The "stop count" is implicitly handled by the outer loop count (each iteration corresponds to one more edge allowed).

//So the structure is really just two loops:
//Outer loop for up to 𝐾+1 relaxations and Inner loop over edges

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){

        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        for(int i=0;i<k+1;i++){  //k stops mean traversing k+1 edges
        vector<int> next=dist;
            for(auto& ele: flights){
                int u=ele[0];
                int v=ele[1];
                int wt=ele[2];
                
                if(dist[u]!=INT_MAX && next[v]>dist[u]+wt){
                    next[v]=dist[u]+wt;
                }
            } 
            dist=next;  //this is done so that we don't use the newly updated value of previous edge to update current edge in same iteration, which would result in more than k stops.            
        }

        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};

