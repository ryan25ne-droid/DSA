class Solution {
public:
    int const arr[4][2]= {{1,0}, {-1,0}, {0,-1}, {0,1}};
    struct Node{
        int row;
        int col;
        int dir;
        int turns;
        int cost;
        Node(int x, int y, int d, int t, int c): row(x), col(y), dir(d), turns(t), cost(c) {};
    };
// right-> 0 dir
// left-> 1
// up-> 2
// down-> 3

    struct Compare {
        bool operator()(const Node& a, const Node& b) const {
            return a.cost > b.cost;  
        }
    };

    int minCost(vector<vector<int>>& grid, int k){
        int m= grid.size();
        int n= grid[0].size();
        int minCost= INT_MAX;

        vector<vector<vector<vector<int>>>>dist(
        m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(k+1, INT_MAX)))
    );
// dist[row][col][dir][turns]

        priority_queue<Node, vector<Node>, Compare> pq;    
        pq.push(Node(0, 0, 0, k, grid[0][0]));
        pq.push(Node(0, 0, 3, k, grid[0][0]));
        dist[0][0][0][k]= grid[0][0];
        dist[0][0][3][k]= grid[0][0];

        while(!pq.empty()){
            auto node= pq.top();
            pq.pop();  

            if(node.row== m-1 && node.col==n-1){
                minCost= min(minCost, node.cost);                
            }

            if (node.cost > dist[node.row][node.col][node.dir][node.turns]){
                continue;
            } 

            for (int d =0; d <4; d++) {
                int nrow = node.row + arr[d][0];
                int ncol = node.col + arr[d][1];
                if (nrow < 0 || ncol < 0 || nrow >= m || ncol >= n){
                    continue;
                }

                int newTurn = node.turns -(d!= node.dir);
                if (newTurn< 0){
                    continue;
                }

                int newCost = node.cost + grid[nrow][ncol];
                if (newCost < dist[nrow][ncol][d][newTurn]){
                    dist[nrow][ncol][d][newTurn] = newCost;
                    pq.push(Node(nrow,ncol, d, newTurn ,newCost));
                }
            }        
        }

        return (minCost== INT_MAX)? -1: minCost;
    }
};