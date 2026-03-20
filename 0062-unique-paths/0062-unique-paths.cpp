class Solution {
public:
// reattempt using dynamic programming
    // int factorial(int n){
    //     if(n==1 || n==0){
    //         return 1;
    //     }
    //     return n*factorial(n-1);
    // }

    //Above code can cause problems as it forces us to find factorial of large numbers to calculate coeff. instead use this

    // int combination(int n,int r){
    //     return factorial(n)/(factorial(r)*factorial(n-r));
    // } 


    long long combination(int n, int r) {
        long long ans = 1;
        for (int i=1;i<=r;i++) {
            ans=ans*(n-r+i)/i;
        }
        return ans;
    }

    int uniquePaths(int m, int n) {
        return (int)combination(m+n-2,m-1);        
    }
};