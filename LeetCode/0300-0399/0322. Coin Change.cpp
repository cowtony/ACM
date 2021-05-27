class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Cost of take each coin is 1.
        // dp[i][j] = min(dp[i - 1][j], dp[i][j - denomination] + 1)
        
        // amount:    | 0 1 2 3 4 5 6 7 8 9 T J
        // -----------|---------------------------
        // coin       | 0 X X X X X X X X X X X
        //            |           |
        // coin 1     | 0 1 2 3 4-5 6 7 8 9 T J
        //            |       |
        // coin 1,2   | 0 1-1-2 2 3 3 4 4 5 5 6
        //            |             |
        // coin 1,2,5 | 0 1-1-2-2-1-2 2 3 3 2 3
        
        vector<int> dp(amount + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int denomination : coins) {
            for (int j = denomination; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - denomination] + 1);
            }
        }
        
        return dp[amount] == INT_MAX / 2? -1 : dp[amount];
    }
};
