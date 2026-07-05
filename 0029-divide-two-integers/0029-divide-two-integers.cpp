class Solution {
public:
    int divide(int dividend, int divisor){
        if(dividend==divisor){
            return 1;
        }
        int sign=1;
        if((dividend<0 && divisor>0)||(dividend>0 && divisor<0)){
            sign=-1;
        }  
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);

        int count=0;
        while(n >= d<<count){
            count++;
        }     
        count--;
        long long ans=0;
        while(count>=0){
            if(n>=(d<<count)){
                n= n-(d<<count);
                ans+=(1ll<<count);
            }
            count--;            
        } 

        if(ans==(1ll<<31) && sign==1){
            return INT_MAX;
        }  
        if(ans==(1ll<<31) && sign==-1){
            return INT_MIN;
        }
        return sign*ans;      
    }
};