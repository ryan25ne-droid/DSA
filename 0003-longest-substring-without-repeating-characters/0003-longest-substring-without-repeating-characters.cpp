class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if(s.size()==1){
            return 1;
        }

        int ptr1=0;
        int ptr2=1;
        int maxLen=0;

        unordered_map<char,int> map;
        map[s[ptr1]]=1;

        while(ptr2<s.size()){
            if(map[s[ptr2]]==0){
                map[s[ptr2]]++;
            }
            else{
                while(map[s[ptr2]]!=0){
                    map[s[ptr1]]--;
                    ptr1++;
                }
                map[s[ptr2]]++;               
            }
            maxLen= max(maxLen, ptr2-ptr1+1);
            ptr2++;
        }
        return maxLen;                        
    }
};