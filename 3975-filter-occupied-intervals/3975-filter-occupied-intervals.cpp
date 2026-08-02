class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& inter, int fStart, int fEnd){
        if(inter.empty()){
            return {};
        }

        vector<vector<int>> ans;
        vector<vector<int>> merged;
        sort(inter.begin(), inter.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        });  

        int a= inter[0][0];
        int b= inter[0][1];

        for(int i=1; i<inter.size(); i++){
            int c= inter[i][0];
            int d= inter[i][1];
            if(b>=c-1){        //overlap. expand current interval
                b= max(b,d);
            }
            else{              
//no overlap. start tracking next interval after pushing current one
                merged.push_back({a,b});
                a=c;
                b=d;
            }
        }  
        merged.push_back({a,b}); // push last interval


        for(int i=0; i<merged.size(); i++){
            int a= merged[i][0];
            int b= merged[i][1];
            if(a< fStart){
                if(b<=fEnd){
                    ans.push_back({a, min(b, fStart-1)});
//Use min so we don't accidentally expand a small interval up to fStart-1
                }
                else{ //b>freeEnd
                    ans.push_back({a, fStart-1});
                    ans.push_back({fEnd+1, b});
                }
            }
            else{  //a>= freeStart
                if(b> fEnd){
                    ans.push_back({max(a,fEnd+1), b});                    
                }
//Use max so we don't accidently expand a small interval back to fEnd +1
            }
        }   
        return ans;         
    }
};

