//optimisations in BFS. Move dir array outside the loop to avoid allocatinng and deallocating space repeatedly.

//instead of maintaining a separate array visited, we can mark a cell 1 to 0 after visiting it to ensure we don't ever visit it  again
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

//initialisation
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 ){
                    grid[i][j]=0;
                    q.push(make_pair(i,j));
                    int size=1;
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        
                        for(auto& ele:dir){
                            int nrow=row+ele[0];
                            int ncol=col+ele[1];
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                                grid[nrow][ncol]=0;
                                q.push(make_pair(nrow,ncol));
                                size++;
                            }
                        }
                    }
                    ans=max(ans,size);
                }
            }
        } 
        return ans;       
    }
};