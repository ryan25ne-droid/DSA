class Solution {
public:
    string smallestPalindrome(string s){
        int arr[26]={0};
        for(int i=0; i<s.size(); i++){
            arr[s[i]-'a']++;
        }

        string special="";
        string first= "";

        for (int i=0; i<26; i++){
            if(arr[i]>0){
                if(arr[i]%2==0){
                    int count= arr[i]/2;
                    first.append(count, 'a'+i);
                }
                else{
                    int count= arr[i]/2;
                    first.append(count, 'a'+i);
                    special+= 'a'+i;
                }
            }
        }
        string second= first;
        reverse(second.begin(), second.end());
        return first+special+second;
    }
};

//reverse doesn't return a string or any other datatype