class Solution {
public:
    unsigned long long change(int target, vector<int>& coins) {

    int n=coins.size();
    vector<unsigned long long>dp(target+1,0);
    // for(int i=0;i<n;i++){  //atleast 1 way to achieve these. but this gives wrong results with dp[0]=1. so avoid this
    //     dp[coins[i]]=1;
    // }

    dp[0]=1; //there is 1 way of achieving 0 target by excluding every coin
    
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=target;j++){  //start j from c so that you avoid acccessing -ve indexes of dp array.
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[target];        
    }
};