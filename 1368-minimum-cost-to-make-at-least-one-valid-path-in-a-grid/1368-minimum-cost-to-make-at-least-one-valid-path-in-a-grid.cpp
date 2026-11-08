class Solution {
    const int dir[4][2]= {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int INF= 1e8;
public:
    int minCost(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        deque<pair<int, int>> dq;
        vector<vector<int>> cost(m, vector<int>(n, INF));

        dq.push_front({0, 0});
        cost[0][0]= 0;

        while(!dq.empty()){
            auto [row, col]= dq.front();
            dq.pop_front();

            if(row== m- 1 && col== n-1){
                return cost[row][col];
            }

            int idx= grid[row][col]- 1;

            for(int i= 0; i< 4; i++){
                int nrow= row+ dir[i][0];
                int ncol= col+ dir[i][1];

                if(nrow>= 0 && nrow< m && ncol>= 0 && ncol< n){
                    if(i== idx){
                        // cost[nrow][ncol]= min(cost[nrow][ncol], cost[row][col]);
// this is bad because in even if no improvement happened, we are still pushing the node again.
                        if(cost[nrow][ncol]> cost[row][col]){
                            cost[nrow][ncol]= cost[row][col];
                            dq.push_front({nrow, ncol});
                        }
                    }
                    else{
                        if(cost[nrow][ncol]> 1+ cost[row][col]){
                            cost[nrow][ncol]= 1+ cost[row][col];
                            dq.push_back({nrow, ncol});
                        }
                    }
                }
            }          
        }

        return cost[m- 1][n- 1];       
    }
};