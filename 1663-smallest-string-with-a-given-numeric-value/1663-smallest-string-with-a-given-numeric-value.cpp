class Solution {
public:
    string getSmallestString(int n, int k) {
        int size=n; //n represents length left to fill. initial n represents string length. But as we fill the string backwards, n decreases. but the total string length (filled+unfilled) should remain hte same.
        int remaining=0;
        string ans(size,'a');
        for(int i=0;i<size;i++){
            remaining=k-(n-1);
            if(remaining>=26){
                ans[size-i-1]='z';
                k=k-26;
            }
            else{
                ans[size-i-1]='a'+(remaining-1);
                k=k-remaining;
            }
            n--;
        }
        return ans;        
    }
};