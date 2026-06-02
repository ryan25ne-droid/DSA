class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> dist(V, INT_MAX);
        vector<bool> MST(V, false);

        dist[0]=0;
        int ans=0;

        for(int i=0; i<V; i++){
            int u =-1;
            for(int j=0; j<V; j++){
                if(!MST[j] && (u==-1 ||dist[j]<dist[u])){
                    u=j;
                }
            }

            MST[u] = true;
            ans+=dist[u];

            for(int v=0; v<V; v++){
                if(!MST[v]){
                    int wt=abs(points[u][0]-points[v][0])+abs(points[u][1] -points[v][1]);

                    dist[v] = min(dist[v], wt);
                }
            }
        }
        return ans;
    }
};

//Sparse graphs (few edges compared to vertices): Using a priority queue (min-heap) is better. It gives 𝑂(𝐸log𝑉), which is efficient when 𝐸 is much smaller than 𝑉^2. That’s why in road networks or graphs with limited connections, the heap-based Prim’s is the right choice.

//Dense graphs (like your LeetCode problem, where every point connects to every other):  Here 𝐸≈𝑉^2. The heap version degenerates to 𝑂(𝑉^2log𝑉). In this case, a simple array-based Prim’s (tracking minDist and scanning linearly) is faster: 𝑂(𝑉^2).
