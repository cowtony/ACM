class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(100000 + 1, -1);  // Can make it to static.
        dp[0] = 0; // false
        
        return willWin(dp, n);
    }
    
    int willWin(vector<int>& dp, int n) {
        if (dp[n] != -1) {
            return dp[n];
        }
        
        for (int i = 1; i * i <= n; i++) {
            if (willWin(dp, n - i * i) == 0) {
                return dp[n] = 1;
            }
        }
        return dp[n] = 0;
    }
};
