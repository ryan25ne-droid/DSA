//we only push '(' in stack as stack keeps track of unmatched characters of longest 'possible' substring. If we have an unmatched ')', the valid substring ends right there. So we will have to frest start. So pushing ')' in stack is a waste
class Solution {
public:
    int longestValidParentheses(string s){
        int maxLen=0;
        stack<int>st;
        int lastValid=-1;

        for(int i=0; i<s.size(); i++){
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
                else{  //if(stack is empty. the current index belongs to an unmatched ')' bracket).
                    lastValid=i;
                }
            }           
        }

        return maxLen;      
    }
};
//lastValid is simply a marker for the last unmatched ')' index. Whenever we encounter an unmatched ')', the valid substring ends right there. Instead of pushing ')' into the stack, you record its index in lastInvalid.

//The next valid substring can only start after this position.