//the main idea is in case of rectangular islands you can use only right and down directions to explore (similar to maze question), but incase of irregualr shape islands you will miss. You have to go in all four directions.

// this is diff from strivers question because DFS is exploring all 8 directions (including diagonals), but the original Number of Islands problem on LeetCode (Q200) only considers 4 directions (up, down, left, right). That’s why your code gives the wrong answer — it merges diagonally‑connected land into one island when the problem statement expects them to be separate.

class Solution {
public:
    void helper(int i, int j, int n, int m, vector<vector<bool>>&visited, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
            
            for(auto &v: dir){
                int nrow= row+v[0];
                int ncol= col+v[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=true;
                } 
            }            
        }
        return;
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