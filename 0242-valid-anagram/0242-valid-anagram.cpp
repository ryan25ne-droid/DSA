class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        //Just a minor optimization

        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        } 
        for(int i=0;i<t.size();i++){
            if(m.count(t[i])==0){
                return false; //key not present
            }
            m[t[i]]--; 
            //if a char exists but its frequency is fewer in s than in t.
            if(m[t[i]]<0){
                return false;
            }
        }

        //Checking if a char exists and its frequency is higher in s than in t 
        // for (auto &p : m) {
        //     if (p.second != 0){
        //         return false;
        //     }
        // } 
//Because the strings are equal length, once we ensured no char in t is used more times than in s, it automatically guarantees no char in s is left over- so the final check is redundant.
        return true;     
    }
};