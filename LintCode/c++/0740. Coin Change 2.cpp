class Solution {
public:
    /**
     * @param amount: a total amount of money amount
     * @param coins: the denomination of each coin
     * @return: the number of combinations that make up the amount
     */
    int change(int amount, vector<int> &coins) {
        // dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        
        // Amount:    | 0 1 2 3 4 5
        // -----------|-------------
        // Coin 0:    | 1 0 0 0 0 0 
        //            |     |
        // Coin 1:    | 1 1-1 1 1 1 
        //            |         |
        // Coin 1,2:  | 1 1 2-2-3 3 
        //            |           |
        // Coin 1,2,5:| 1-1-2-2-3-4 
        
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin_value : coins) {
            for (int j = coin_value; j <= amount; j++) {
                dp[j] += dp[j - coin_value];
            }
        }
        
        return dp[amount];
    }
};
