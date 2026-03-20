class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s= to_string(x);
        string ans;
        for(int i=0;i<s.size();i++){
            ans+=s[i];
        }   
        if(ans==s){
            return true;
        }   
        else{
            return false;
        }
    }
};