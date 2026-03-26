class Solution {
public:
    string largestOddNumber(string str) {
        int n=str.size();
        string substr="";
        string evenseen="";
        for(int i=0;i<n;i++){
            if(str[i]=='1' ||str[i]=='3'||str[i]=='5'||str[i]=='7'|| str[i]=='9'){substr+=evenseen;
            substr+=str[i]; 
            evenseen="";               
            }
            else{
                evenseen+=str[i];
            }
        }
        return substr;                
    }
};