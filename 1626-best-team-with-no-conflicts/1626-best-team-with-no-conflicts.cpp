class Solution {
public:
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

        vector<int> dp(n);
        for(int i=0; i<n; i++){
            dp[i]= player[i].second;
        }

        int ans= INT_MIN;

        for(int i= 0; i<n; i++){
            for(int j= 0; j<i; j++){
                if(player[i].second>= player[j].second){
                    dp[i]= max(dp[i], dp[j]+ player[i].second);
                }
            }
            ans= max(ans, dp[i]);
        }

        return ans;                
    }
};

// If we don't sort by scores in same age grp, then a problem happens,
// My current code if(currAge> prevAge && currScore< prevScore) then invalid

// but if both age grps are same we can include currScore. But that might not always be true.

// eg (20, 80), (21, 100), (21, 70). Code looks back at 100. Sees 100> 70 but age is same. Includes 70 wrongly cause 80 should block 70 but it doesn't.

