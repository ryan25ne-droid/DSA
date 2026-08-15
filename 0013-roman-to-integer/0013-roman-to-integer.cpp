class Solution {
public:
    int romanToInt(string s){
        int n= s.size();
        unordered_map<char,int> mpp;
        int ans=0;
//this stores value of individual alphabets
        mpp['I'] =1;
        mpp['V'] =5;
        mpp['X'] =10;
        mpp['L'] =50;
        mpp['C'] =100;
        mpp['D'] =500;
        mpp['M'] =1000;

        char curr= s[0];
        char prev= {};

        for(int i=1; i<n; i++){
            prev= curr;
            curr= s[i];

            if(mpp[prev] < mpp[curr]){
                ans-= mpp[prev];                
            }
            else{
                ans+= mpp[prev];
            }
        } 
        ans+= mpp[curr];
        return ans;       
    }
};