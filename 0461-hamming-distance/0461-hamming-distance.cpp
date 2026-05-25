class Solution {
public:
    int hammingDistance(int x, int y) {
        int z= x^y;     //XOR
        int count=0;
        while(z){
            if(z&1){
                count++; // check last bit
            }
            z>>= 1;            // shift right
        }
        return count;
    }
};