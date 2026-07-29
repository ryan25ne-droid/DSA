class Solution {
public:
    string smallestPalindrome(string s){
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        char ptr='a';
        string first= "";

        if(s.size()%2==0){  //even str case
            while(ptr<='z'){
                if(mp.count(ptr)!=0){
                    int count= mp[ptr]/2;
                    while(count>0){
                        first+= ptr;
                        count--;
                    }
                }
                ptr++;
            }
            string second= first;
            reverse(second.begin(), second.end());
            return first+second;
        }
        else{  //odd str case
            string special="";
            while(ptr<='z'){
                if(mp.count(ptr)!=0 && mp[ptr] %2==0){
                    int count= mp[ptr]/2;
                    while(count>0){
                        first+= ptr;
                        count--;
                    }
                }
                else if(mp.count(ptr)!=0 && mp[ptr] %2!=0){
                    int count= mp[ptr]/2;
                    while(count>0){
                        first+=ptr;
                        count--;
                    }
                    special.push_back(ptr);
                }
                ptr++;
            }
            string second= first;
            reverse(second.begin(), second.end());
            return first+special+second;
        }
        return "";
    }
};

//reverse doesn't return a string or any other datatype