class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int n= s.size();
        int maxLen= 0;
        int l= 0;
        unordered_map<char, int> mpp;

        for(int r= 0; r< n; r++){
            mpp[s[r]]++;
            
            while(mpp[s[r]]> 1){
                mpp[s[l]]--;
                l++;
            }
            maxLen= max(maxLen, r- l+ 1);
        } 

        return maxLen;       
    }
};