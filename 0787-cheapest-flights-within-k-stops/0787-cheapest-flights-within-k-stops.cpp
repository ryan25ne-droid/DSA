class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto &ele : flights) {
            graph[ele[0]].push_back({ele[1], ele[2]});
        }

        vector<vector<int>> dist(n, vector<int>(K+2, INT_MAX));
        dist[src][K+1] = 0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, K+1});

        while(!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if(node == dst){
                return cost;
            }

            if(stops>0) {
                for(auto &[next, price] : graph[node]) {
                    if(cost+price< dist[next][stops-1]) {
                        dist[next][stops-1]= cost+price;
                        pq.push({cost+price, next, stops-1});
                    }
                }
            }
        }
        return -1;
    }
};

