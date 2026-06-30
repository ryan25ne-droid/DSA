class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& inter, int freeStart, int freeEnd){
        if (inter.empty()){
            return {};
        }

        vector<vector<int>>ans;
        sort(inter.begin(), inter.end());

        int a=inter[0][0];
        int b=inter[0][1];

        for(int i=1;i<inter.size();i++){
            int c= inter[i][0];
            int d= inter[i][1]; 

            if(b>=c-1){  //overlap. extend interval
                b=max(b,d); 
            } 
            else{  //no overlap
                ans.push_back({a,b});
                a=c;
                b=d;
            }                       
        }
        ans.push_back({a,b});  //last interval
        int n= ans.size();

        for(int i=0;i<n;i++){
            if(ans[i][0]<freeStart){
                if(ans[i][1]<=freeEnd){
                    ans.push_back({ans[i][0], min(ans[i][1],freeStart-1)}); 
//Use min so we don't accidentally expand a small interval up to freeStart-1
                }
                else{
                    ans.push_back({ans[i][0], freeStart-1}); 
                    if(freeEnd+1<= ans[i][1]){ 
                        ans.push_back({freeEnd+1, ans[i][1]});
                    }
                }
            }
    
            else{     //ans[i][0]>=freeStart
                if(ans[i][1]>freeEnd){
                    ans.push_back({max(ans[i][0], freeEnd+1), ans[i][1]}); 
//Use max so we don't accidently expand a small interval back to freeEnd+1
                }
            }
        }

        ans.erase(ans.begin(), ans.begin()+n);
        //since we already sorted ans once and iterated on it in that order, the final order is also ascending. No need to do sorting again

        return ans;
    }
};

//there were problems regarding inplace modification of ans as erasing alters the elements and ends up skipping some elements. At first I thought that keep adding intervals at the back which are not overlapped. But we still have to remove the completely overlapped intervals in that case which is messy.

// for(int i=0;i<ans.size();i++){
//             if(ans[i][0]<=freeStart){
//                 if(ans[i][1]<=freeEnd){
//                     ans[i]={ans[i][0], freeStart-1};
//                 }
//                 else{
//                     ans[i]={ans[i][0], freeStart-1};
//                     ans.push_back({freeEnd+1, ans[i][1]});
//                     break;
//                 }
//             }
//             if(ans[i][0]>freeStart){
//                 if(ans[i][1]<=freeEnd){
//                     ans.erase(ans.begin()+i);
//                 }
//                 else{
//                     ans[i]={freeEnd+1,ans[i][1]};
//                     break;
//                 }
//             }
//         }

//so instead we push all 