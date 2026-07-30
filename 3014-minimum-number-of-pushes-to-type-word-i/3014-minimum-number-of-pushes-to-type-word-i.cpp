class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash_map(26);

        for(int i=0; i<word.size(); i++){
            hash_map[word[i]-'a']++;
        }

        sort(hash_map.rbegin(), hash_map.rend());
// this is for descending order sorting

        int ans=0;
        int elements=0;

        for(int i=0; i<26; i++){
            ans+= hash_map[i]*((elements/8)+1);
            elements++;
        }
        return ans;        
    }
};