class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(m,false));

//initialisation
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    visited[i][j]=true;
                    q.push(make_pair(i,j));
                    int size=1;
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
                        for(auto& ele:dir){
                            int nrow=row+ele[0];
                            int ncol=col+ele[1];
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                                visited[nrow][ncol]=true;
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