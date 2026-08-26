class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!= goal.size()){
            return false;
        }
        
        unordered_map<char, vector<int>> mpp;
        
        for(int i=0; i<s.size(); i++){
            mpp[s[i]].push_back(i);
        }
        
        int state=1;
               
        
        for(int i=0; i<s.size(); i++){
            if(s[i]== goal[i]){
                continue;
            }  
            else{
                if(state==0){
                    return false;
                }
                
                for(auto& idx: mpp[goal[i]]){
                    if(s[i]== goal[idx]){
                        s[i]= goal[i];
                        s[idx]= goal[idx];
                        state= 0;
                    }
                }
                if(state==1){
                    return false;
                }
            }
        }
        if(state==0){
            return true;
        }
        if(state==1){  //string matched without a single swap
            for(int i=0; i<s.size(); i++){
                if(mpp[s[i]].size()>1){
                    return true;
                }
            }            
        }
        return false;
                
    }
};