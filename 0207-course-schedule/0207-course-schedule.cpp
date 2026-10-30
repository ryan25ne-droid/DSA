class Solution {
public:
    bool helper(vector<int> &state, int i, vector<vector<int>> &adj){

        if(state[i]== 2){
            return false;
        }

        if(state[i]== 0){
            state[i]= 2;

            for(auto& v: adj[i]){
                if(!helper(state, v, adj)){
                    return false;
                }
            }
            state[i]= 1;
        }  
        return true;              
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        int n= numCourses;
        vector<vector<int>> adj(n);

        for(auto& ele: prerequisites){
            int u= ele[1];
            int v= ele[0];

            adj[u].push_back(v);            
        } 

        vector<int> state(n, 0);
// 0-> unvisited. 1-> visited. 2-> visited in same path (recStack)

        for(int i=0; i<n; i++){
            if(state[i]== 0){
                if(!helper(state, i, adj)){
                    return false;
                }
            }
        }

        return true;
    }
};