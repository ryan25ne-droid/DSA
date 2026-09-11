class Solution {
public:
    int helper(vector<pair<int, int>> &player, vector<vector<int>> &dp, int idx, int prevIdx, int n){

        if(idx== n){
            return 0;
        }

        if(dp[idx][prevIdx+1]!= -1){
            return dp[idx][prevIdx+1];
        } 

// No previous player
        if (prevIdx == -1) {
            return dp[idx][prevIdx+1] = max(helper(player, dp, idx+1, -1, n), player[idx].second + helper(player, dp, idx + 1, idx, n));
        }

        int currScore= player[idx].second;
        int prevScore= player[prevIdx].second;

        if(currScore< prevScore){
            return dp[idx][prevIdx+1]= helper(player, dp, idx+1, prevIdx, n);
        }

        return dp[idx][prevIdx+1]= max(helper(player, dp, idx+1, prevIdx, n), player[idx].second + helper(player, dp, idx+1, idx, n));        
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n= ages.size();

        vector<pair<int, int>> player;

        for(int i=0; i<n; i++){
            player.push_back({ages[i], scores[i]});  //{age, score} pair
        }

        sort(player.begin(), player.end(), [](auto& a, auto& b){
            if(a.first== b.first){
                return a.second< b.second;
            }
            return a.first< b.first;
        });

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return helper(player, dp, 0, -1, n);
                
    }
};

// If we don't sort by scores in same age grp, then a problem happens,
// My current code if(currAge> prevAge && currScore< prevScore) then invalid

// but if both age grps are same we can include currScore. But that might not always be true.

// eg (20, 80), (21, 100), (21, 70). Code looks back at 100. Sees 100> 70 but age is same. Includes 70 wrongly cause 80 should block 70 but it doesn't.

