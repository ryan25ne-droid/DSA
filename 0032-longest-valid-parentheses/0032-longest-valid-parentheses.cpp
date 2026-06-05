//we only push '(' in stack as stack keeps track of unmatched characters of longest 'possible' substring. If we have an unmatched ')', the valid substring ends right there. So we will have to frest start. So pushing ')' in stack is a waste
class Solution {
public:
    int longestValidParentheses(string s){
        int n=s.size();
        int maxLen=0;
        stack<int>st;
        int lastValid=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            } 
            else{  //s[i]=')'
                if(!st.empty()){
                    st.pop();
                    if(st.empty()){
                        maxLen= max(maxLen, i-lastValid);
                    }
                    else{
                        maxLen=max(maxLen, i-st.top());
                    }
                }
                else{
                    lastValid=i;
                }
            }           
        }

        return maxLen;      
    }
};