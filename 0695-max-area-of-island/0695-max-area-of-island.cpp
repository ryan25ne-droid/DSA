class Solution {
public:
    int helper(int i, int j, int n, int m, vector<vector<bool>>&visited, vector<vector<int>>& grid){

        visited[i][j]=true;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int ans=1;  //count current cell

        for(auto&ele: dir){
            int nrow= i+ele[0];
            int ncol= j+ele[1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                ans+=helper(nrow,ncol,n,m,visited,grid);
            }
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        int Max=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    Max=max(Max, helper(i,j,n,m,visited,grid));
                }
            }
        }
        return Max;
    }
};