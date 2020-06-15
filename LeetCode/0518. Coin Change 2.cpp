class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        
        // Amount:    | 0 1 2 3 4 5
        // -----------|-------------
        // Coin 0     | 1 0 0 0 0 0 
        //            |     |
        // Coin 1     | 1 1-1 1 1 1 
        //            |         |
        // Coin 1,2   | 1 1 2-2-3 3 
        //            |           |
        // Coin 1,2,5 | 1-1-2-2-3-4 
        
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int denomination : coins) {
            for (int j = denomination; j <= amount; j++) {
                dp[j] += dp[j - denomination];
            }
        }
        
        return dp[amount];
    }
};
