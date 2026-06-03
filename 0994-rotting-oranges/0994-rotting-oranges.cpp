//the idea is BFS traversal. If an orange 2 is in neighborhood of 1, then convert the 1 into a 2. ALso keep track of the variable time. If you encounter a 0, do nothing. when BFS finishes, if you find any 1, return -1. Else return the max value of the minute.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>>q;

//initialisation at minute 0    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        } 

        int minute=0;

        while(!q.empty()){
            vector<int> v=q.front();
            int row=v[0];
            int col=v[1];
            minute=v[2];
            q.pop();
            int dir[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto& ele:dir){
                int nrow=row+ele[0];
                int ncol=col+ele[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({nrow,ncol, minute+1});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minute;
    }
};