class Solution {
public:
    string minWindow(string s, string t) {
        int start=0;

        unordered_map<char, int> mpp;
        for(int i=0; i<t.size(); i++){
            mpp[t[i]]++;
        }

        int l=0;
        int minLen= INT_MAX;
        int unique=0;
        int count= mpp.size();
        unordered_map<char, int> trav;

        for(int r=0; r<s.size(); r++){
            trav[s[r]]++;
            if(trav[s[r]]== mpp[s[r]]){
                unique++;
            }
            while(unique== count){
                if(minLen > r-l+1){
                    start= l;
                    minLen= r-l+1;
                }
                trav[s[l]]--;
                if(trav[s[l]] < mpp[s[l]]){
                    unique--;
                }
                l++;
            }
        }

        return (minLen == INT_MAX)? "" : s.substr(start, minLen);        
    }
};