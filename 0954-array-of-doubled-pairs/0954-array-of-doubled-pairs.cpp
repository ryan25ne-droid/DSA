class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) { 
        int n= arr.size();

        sort(arr.begin(), arr.end(), [](int a, int b){
            return abs(a)<abs(b);
        });

        unordered_map<int,int> mpp;

        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }

        for(int i=0; i<n; i++){
            if(mpp[arr[i]]==0){  //nums[i] already used
                continue;
            }  
            if(mpp[2* arr[i]]==0){
                return false;
            } 
            mpp[arr[i]]--;
            mpp[2*arr[i]]--;   
        } 

        return true;                   
    }
};