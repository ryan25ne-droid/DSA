class Solution {
public:
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        // Base case: all matchsticks placed successfully
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target;
        }

// Place current matchstick into each of the 4 sides
        for (int i = 0; i< 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index]; // Do
                
                if (backtrack(matchsticks, sides, index + 1, target)) return true;
                
                sides[i] -= matchsticks[index]; // Undo (Backtrack)
            }
            
            // Optimization: if this side is empty, trying other empty sides is redundant
            if (sides[i] == 0) break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }

        int target = sum/4;
        vector<int> sides(4, 0);

//Sort descending to maximize pruning efficiency
        sort(matchsticks.rbegin(), matchsticks.rend());

        return backtrack(matchsticks, sides, 0, target);
    }
};