class Solution {
public:
    string largestOddNumber(string str) {
        int n=str.size();
        string substr="";
        int lastodd=-1;
        for(int i=n-1;i>=0;i--){
            if(str[i]=='1' ||str[i]=='3'||str[i]=='5'||str[i]=='7'|| str[i]=='9'){lastodd=i;
        break;
            }
        }
        return str.substr(0,lastodd+1);                
    }
};