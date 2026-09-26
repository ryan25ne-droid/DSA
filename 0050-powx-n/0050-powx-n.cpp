class Solution {
public:
    double myPow(double x, int n) {

        if(x==0 || x==1 || n==1){
            return x;
        } 

        if(n==0){
            return 1;
        } 

        long long N= n;

        if(n< 0){
            x= 1/x;
            N= -N;
        }

        double base= x;
        long long pow= N;
        double ans= 1;

        while(pow> 0){
            if(pow%2 ==1){
                ans= ans*base;
            }

            base= base*base;
            pow= pow/2;
        }

        return ans;      
    }
};