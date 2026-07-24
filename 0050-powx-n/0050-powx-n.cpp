class Solution {
public:
    double myPow(double x, int n) {
        bool flag=false;
        long long m=n;
        if(m<0){
            m*=-1;
            flag=true;
        }
        if (m == 0)
            return 1;
        double ot = 1;
        while (m > 0) {
            if (m % 2 == 0) {
                x *= x;
                m /= 2;
            } else {
                ot *= x;
                m--;
            }
        }
        if(flag){
            return 1/ot;
        }
        return ot;
    }
};