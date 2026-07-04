class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){
        int n= arr.size();
        vector<int> answer;
        vector<int> prefix(n);  //prefix[i] stores sum of elements from 0 to i.

        prefix[0]= arr[0];
        for(int i=1; i<n ; i++){
            prefix[i]= prefix[i-1] ^ arr[i];
        }

        for(auto&ele: queries){
            int start= ele[0];
            int end= ele[1];
            
            if(start==0){
                answer.push_back(prefix[end]);
            }
            else{
                answer.push_back(prefix[start-1] ^ prefix[end]);
            }
        }
        return answer;        
    }
};