class Solution {
public:
int helper(int n, vector<int>&f){
    if(n==1 ||n==0){
        f[n]=1;
        return 1;
    }
    if(f[n]!=-1){
        return f[n];
    }
    f[n]=helper(n-1,f)+helper(n-2,f);
    return f[n];
}


    int climbStairs(int n) {
        vector<int> f(n+1,-1);
        return helper(n,f);                
    }
};