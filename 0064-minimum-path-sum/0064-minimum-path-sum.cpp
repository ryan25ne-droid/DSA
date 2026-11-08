class Solution {
public:
    const int INF= 1e8;
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();

        vector<int> prev(n, INF);
        vector<int> curr(n, 0);
        
        curr[0]= grid[0][0];

        for(int i= 0; i< m; i++){  
            for(int j= 0; j< n; j++){
                if(i== 0 && j== 0){
                    continue;
                }
                curr[j]= grid[i][j]+  min((j> 0)? curr[j-1]: INF, prev[j]);
            }
            prev= curr;
        }

        return curr[n- 1];        
    }
};

// optimising in space