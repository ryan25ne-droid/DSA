class Solution {
public:
    int distinctIntegers(int n) {
        if(n==1){
            return 1;
        }

        unordered_set<int> s;
        for(int i=2;i<=n;i++){
            s.insert(i);                        
        }   
        return s.size();      
    }
};