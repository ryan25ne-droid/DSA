//the idea is BFS traversal. If an orange 2 is in neighborhood of 1, then convert the 1 into a 2. ALso keep track of the variable time. If you encounter a 0, do nothing. when BFS finishes, if you find any 1, return -1. Else return the max value of the minute.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<tuple<int,int,int>>q;

//initialisation at minute 0    
        int fresh=0;  //keeps track of fresh oranges in our loop

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_tuple(i,j,0));
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        } 

        int minute=0;

        while(!q.empty()){
            auto [row,col,t]= q.front();
            minute=t;

            q.pop();

            int dir[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto& ele:dir){
                int nrow=row+ele[0];
                int ncol=col+ele[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push(make_tuple(nrow,ncol, minute+1));
                    fresh--;
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }

        return fresh==0 ? minute:-1;
    }
};

//use tuples. dynamically less heavy as compared to vectors