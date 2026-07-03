class Solution {
public:
    int reverseBits(int n){
        int p2=1; 
        int ans=0;

// start from 30 to exclude last signed bit
        for(int i=31;i>=0;i--){
            if(n & (1<<i)){
                ans+=p2;
            }
            p2=p2 << 1;
        }
        return ans;        
    }
};