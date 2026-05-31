class Solution {
public:
    void Djikstra(vector<vector<pair<int,int>>> &adj,vector<int>&dist, int k){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//pq stores {distance, node}

        dist[k]=0;
        pq.push(make_pair(dist[k],k));

        while(!pq.empty()){
            auto [d,u]= pq.top();
            pq.pop();

            if(d>dist[u]){
                continue;
            }

            for(auto& [wt,v]: adj[u]){
                if(dist[v] > dist[u] +wt){
                    dist[v]=dist[u]+wt;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k){

        vector<vector<pair<int,int>>>adj(n+1);
//adj[u] is a vector of vectors of size 2 (wt,v) i,e, (weight, node)

        for(auto&ele: times){
            int u= ele[0];
            int v= ele[1];
            int wt= ele[2];
            adj[u].push_back(make_pair(wt,v));
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

//In Dijkstra, whenever we find a shorter path to a node v, we push (dist[v],v) into the priority queue.

//But we don’t remove the old entry (oldDist, v) that might already be in the queue.

//So the queue can contain multiple entries for the same node, with different distances.

//When we pop from the queue, we might get a stale entry (with a distance larger than the current best dist[v]).