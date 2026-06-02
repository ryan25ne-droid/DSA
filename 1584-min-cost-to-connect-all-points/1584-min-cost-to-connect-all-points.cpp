class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int V= points.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<bool> MST(V,false);
        
        int ans=0;

        pq.push(make_pair(0,0));  //src=0 vertex with its distance as 0 from itself

        while(!pq.empty()){
            int u= pq.top().second;
            int cost=pq.top().first;
            pq.pop();

            if(!MST[u]){
                MST[u]=true;
                ans+=cost;

                for(int v=0; v<V; v++){
                    if(u!=v){
                        int wt= abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                        pq.push(make_pair(wt,v));
                    }
                }
            }
        }
        return ans;
    }
};