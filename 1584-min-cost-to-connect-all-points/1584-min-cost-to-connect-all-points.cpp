class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> dist(V, INT_MAX);
        vector<bool> inMST(V, false);

        dist[0]=0;
        int ans=0;

        for(int i=0; i<V; i++){
            int u =-1;
            for(int j=0; j<V; j++){
                if(!inMST[j] && (u==-1 ||dist[j]<dist[u])){
                    u=j;
                }
            }

            inMST[u] = true;
            ans+=dist[u];

            for(int v=0; v<V; v++){
                if(!inMST[v]){
                    int wt=abs(points[u][0]-points[v][0])+abs(points[u][1] -points[v][1]);

                    dist[v] = min(dist[v], wt);
                }
            }
        }
        return ans;
    }
};
