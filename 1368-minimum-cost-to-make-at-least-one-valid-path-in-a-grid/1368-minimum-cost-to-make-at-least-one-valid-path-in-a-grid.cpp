class Solution {
    int dir[4][2]= {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  //mapping at idx should be consistent with the idx+1 direction given in ques
    const int INF= 1e8;

public:
    int minCost(vector<vector<int>>& grid){
        int m= grid.size();
        int n= grid[0].size();
        deque<pair<int, int>> dq; //we store i, j
        vector<vector<int>> dist(m, vector<int>(n, INF));

        dist[0][0]= 0;
        dq.push_front({0, 0});

        while(!dq.empty()){
            auto [i, j]= dq.front();
            dq.pop_front();

            int num= grid[i][j];

            for(int k= 0; k<4; k++){
                int nrow= i+ dir[k][0];
                int ncol= j+ dir[k][1];

                int wt= (num== k+1)? 0: 1;

                if(nrow>= 0 && nrow< m && ncol>= 0 && ncol< n){
                    if(dist[nrow][ncol]> dist[i][j]+ wt){
                        dist[nrow][ncol]= dist[i][j] +wt;
                        if(wt== 0){
                            dq.push_front({nrow, ncol});
                        }
                        if(wt== 1){
                            dq.push_back({nrow, ncol});
                        }
                    }
                }
            }
        }

        return dist[m-1][n-1];        
    }
};