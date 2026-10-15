class Solution {
public:
    bool helper(vector<bool> &Tidi, vector<bool> &visited, int i, vector<vector<int>> &adj){

        if(Tidi[i]){
            return false;
        }

        if(!visited[i]){
            visited[i]= true;
            Tidi[i]= true;

            for(auto& v: adj[i]){
                if(!helper(Tidi, visited, v, adj)){
                    return false;
                }
            }
            Tidi[i]= false;
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

        vector<bool> Tidi(n, false);
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(!helper(Tidi, visited, i, adj)){
                    return false;
                }
            }
        }

        return true;
    }
};