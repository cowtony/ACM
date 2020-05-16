class Solution {
public:
    /**
     * @param dungeon: a 2D array
     * @return: return a integer
     */
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        // Create DP matrix with a right and bottom boarder.
        vector<vector<int>> dp(dungeon.size() + 1, vector<int>(dungeon[0].size() + 1, INT_MAX));
        dp[dungeon.size()][dungeon[0].size() - 1] = 1;
        dp[dungeon.size() - 1][dungeon[0].size()] = 1;
        
        for (int r = dungeon.size() - 1; r >= 0; r--) {
            for (int c = dungeon[0].size() - 1; c >= 0; c--) {
                dp[r][c] = max(1, min(dp[r][c + 1], dp[r + 1][c]) - dungeon[r][c]);
            }
        }
        
        return dp[0][0];
    }
};
