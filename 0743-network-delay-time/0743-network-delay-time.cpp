class Solution {
public:
    void Djikstra(vector<vector<vector<int>>>&adj,vector<int>&dist, int k){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//pq stores {distance, node}

        dist[k]=0;
        pq.push(make_pair(dist[k],k));

        while(!pq.empty()){
            int u= pq.top().second;
            pq.pop();
//adj[u] is a vector of vectors of size 2 (wt,v) i,e, (weight, node)
            for(auto&ele: adj[u]){
                if(dist[ele[1]]>dist[u]+ele[0]){
                    dist[ele[1]]=dist[u]+ele[0];
                    pq.push(make_pair(dist[ele[1]],ele[1]));
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k){

        vector<vector<vector<int>>>adj(n+1);

        for(auto&ele: times){
            int u= ele[0];
            int v= ele[1];
            int wt= ele[2];
            adj[u].push_back({wt,v});
        }  

        vector<int>dist(n+1,INT_MAX);

        Djikstra(adj,dist,k);

        int Max=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            Max=max(Max,dist[i]);
        }
        return Max;
    }
};