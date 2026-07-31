class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if(s.size()==1){
            return 1;
        }

        int ptr1=0;
        int ptr2=1;
        int maxLen=0;

        unordered_set<char> map;
        map.insert(s[ptr1]);

        while(ptr2<s.size()){
            if(map.count(s[ptr1])==0){
                map.insert(s[ptr2]);
            }
            else{
                while(map.count(s[ptr2])!=0){
                    map.erase(s[ptr1]);
                    ptr1++;
                }
                map.insert(s[ptr2]);               
            }
            maxLen= max(maxLen, ptr2-ptr1+1);
            ptr2++;
        }
        return maxLen;                        
    }
};