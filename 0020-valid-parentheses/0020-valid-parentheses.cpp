class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        int n= s.size();
        unordered_map<char, char> mpp;
        mpp[')']= '(';
        mpp['}']= '{';
        mpp[']']= '[';

        for(int i= 0; i< n; i++){
            if(s[i]== ')' || s[i]== '}' || s[i]== ']'){
                if(st.empty() || st.top()!= mpp[s[i]]){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        return st.empty();        
    }
};