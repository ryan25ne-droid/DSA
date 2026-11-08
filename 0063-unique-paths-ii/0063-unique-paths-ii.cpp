class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();

        if(obstacleGrid[0][0]== 1 || obstacleGrid[m-1][n-1]== 1){
            return 0;
        }

        vector<int> curr(n, 0);
        vector<int> prev(n, 0); 
        curr[0]= 1;  //no of ways to reach (0, 0)

        for(int i= 0; i< m; i++){
            for(int j= 0; j< n; j++){
                if(i== 0 && j== 0){
                    continue;
                }
// important condition

                if(obstacleGrid[i][j]== 1){
                    curr[j]= 0;
                }
                else{
                    curr[j]= ((j> 0)? curr[j-1]: 0)+ ((i> 0)? prev[j]: 0);
                }
            }
            swap(curr, prev);
        }  

        return prev[n-1];     
    }
};


//space optimisations