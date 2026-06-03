// classical ques of finding a disjoint set
class Disjoint_Set{
public:
    int n;
    vector<int>parent;
    vector<int>rank;

    Disjoint_Set(int n){
        this->n=n;
        parent.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){  //initialising the parent and rank vectors
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        else{
            return parent[x]=find(parent[x]);    //path compression
        }
    }

    void unionByRank(int a, int b){
        int parA=find(a);
        int parB=find(b);

        if(rank[parA]==rank[parB]){
            parent[parB]=parA;
            rank[parA]++;
        }
        else if(rank[parA]>rank[parB]){
            parent[parB]=parA;
        }
        else{
            parent[parA]=parB;
        }
    }
    bool findSet(int a, int b){  //do a and b belong in same set?
        int parA=find(a);
        int parB=find(b);

        if(parA==parB){
            return true;
        }
        return false;        
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n=edges.size();
        Disjoint_Set DJ(n+1);

        for(auto& ele:edges){
            int u=ele[0];
            int v=ele[1];

            if(DJ.findSet(u,v)){
                return ele;
            }
            else{
                DJ.unionByRank(u,v);
            }
        }   
        return {}; //should never reach here iff input graph has a redundant edge
    }
};