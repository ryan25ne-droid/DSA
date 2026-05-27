//the main idea is in case of rectangular islands you can use only right and down directions to explore (similar to maze question), but incase of irregualr shape islands you will miss. You have to go in all four directions.

// this is diff from strivers question because DFS is exploring all 8 directions (including diagonals), but the original Number of Islands problem on LeetCode (Q200) only considers 4 directions (up, down, left, right). That’s why your code gives the wrong answer — it merges diagonally‑connected land into one island when the problem statement expects them to be separate.

class Solution {
public:
    void helper(int i, int j,int n, int m, vector<vector<bool>>&visited, vector<vector<char>>&grid){

        visited[i][j]=true;
        // for (int delrow=-1; delrow<=1; delrow++){
        //     for(int delcol=-1; delcol<=1;delcol++){
        //         int ni=i+delrow;
        //         int nj=j+delcol;
        //         if(delrow==0 && delcol==0){
        //             continue;  //skip the same cell to avoid infinite recursion
        //         }
        //         if(0<=ni && ni<n && 0<=nj && nj<m && grid[ni][nj]=='1' && !visited[ni][nj]){
        //             helper(ni,nj,n,m,visited,grid);
        //         }
        //     }
        // }
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; // down, up, right, left
        for (auto& d:dirs) {
            int ni=i+d[0], nj=j+d[1];
            if (ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='1' && !visited[ni][nj]) {
                helper(ni,nj,n,m,visited,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    helper(i,j,n,m,visited,grid);
                    count++;
                }
            }
        }
        return count;        
    }
};