struct State{
    int i,j, moves;
    long long cost;

    State(long long cost, int i, int j, int moves){
        this->cost= cost;
        this->i= i;
        this->j= j;
        this->moves= moves;
    }
    bool operator<(const State &other)const{
        return cost>other.cost; 
    }
};

class Solution {
public:
    int const dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    
    long long minCost(int m, int n, vector<vector<int>>& penalty){
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        vector<vector<vector<long long>>>dp(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));
        dp[0][0][0]=1;

//dp[i][j][k] tracks min cost to reach i,j with moves k. k->0 if the no of moves to reach (i,j) is even. otherwise odd, k->1
        priority_queue<State>pq;

        pq.push(State(1,0,0,0));

        while(!pq.empty()){
            State curr= pq.top();
            long long cost= curr.cost;
            int i= curr.i;
            int j= curr.j;
            int moves= curr.moves;
            pq.pop();

            if(i==m-1 && j==n-1){
                return cost;
            }
            if(cost> dp[i][j][moves]){
                continue;
            }  
            
//try waiting
            long long waitCost= cost+ penalty[i][j];
            if(waitCost< dp[i][j][1-moves]){
                dp[i][j][1-moves]= waitCost;
                pq.push(State(waitCost, i, j, 1-moves));
            }
//try all 4 directions
            for(auto& ele:dir){
                int nrow= i+ele[0];
                int ncol= j+ele[1];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    long long entryCost= cost+(nrow+1)*(ncol+1);
                    bool follows_parity=false;

                    if(moves==0){
// current movesi>even. so you enter neighbours on odd-numbered action
                        if(ele[0]==1 || ele[1]==1){
                            follows_parity= true;
                        }
                    }
                    else if(moves==1){
                        if(ele[0]==-1 || ele[1]==-1){
                            follows_parity= true;
                        }
                    }
                    if(!follows_parity){
                        entryCost+= penalty[i][j];
                    }
                    if(entryCost< dp[nrow][ncol][1-moves]){
                        dp[nrow][ncol][1-moves]= entryCost;
                        pq.push(State(entryCost, nrow, ncol, 1-moves));
                    }
                }
            }
            
        }
        return -1;
    }
};