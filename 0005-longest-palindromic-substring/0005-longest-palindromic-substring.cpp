class Solution {
public:
    string longestPalindrome(string s){
        int n= s.size();
        int maxLen= 1;
        int start=0;

        for(int i=0; i<n; i++){
            int len= 1;
            int left= i-1;
            int right= i+1;
// odd palindrome
            while(left>=0 && right<n && s[left]== s[right]){
                len+=2;
                right++;
                left--;
            }
            if(maxLen< len){
                maxLen= len;
                start= left+1;
            }
        } 

        for(int i=0; i<n; i++){
            int len=0;
            int left=i; 
            int right= i+1;
            while(left>=0 && right<n && s[left]== s[right]){
                len+=2;
                right++;
                left--;
            }
            if(maxLen< len){
                maxLen= len;
                start= left+1;
            }
        }
        return s.substr(start, maxLen);     
    }
};