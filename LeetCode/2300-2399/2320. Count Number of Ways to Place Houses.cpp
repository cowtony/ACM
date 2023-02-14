class Solution {
public:
    int countHousePlacements(int n) {
        int kMod = 1000000007;
        // One side has no effect to another side.
        // For one side it's Fibonacci:
        // dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        // dp[i][1] = dp[i - 1][0];
        
        int64_t a = 0, b = 1;
        for (int i = 1; i <= n; i++) {
            int temp = b;
            b = (a + b) % kMod;
            a = temp;
        }
        return (a + b) * (a + b) % kMod;
    }
};
