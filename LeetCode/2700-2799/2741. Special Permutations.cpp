class Solution {
public:
    static const int kMod = 1e9 + 7;

    int specialPerm(vector<int>& nums) {
        int N = nums.size();

        vector<vector<int>> dp(1 << N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            dp[1 << i][i] = 1;
        }

        for (int state = 1; state < (1 << N); state++) {
            // Enumerate every selected number as last number.
            for (int i = 0; i < N; i++) {
                if ((state & 1 << i) == 0) {
                    continue;
                }

                // For every other number in the state:
                for (int j = 0; j < N; j++) {
                    if (i == j || (state & 1 << j) == 0) {
                        continue;
                    }
                    if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                        dp[state][i] = (dp[state][i] + dp[state ^ (1 << i)][j]) % kMod;
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            result = (result + dp[(1 << N) - 1][i]) % kMod;
        }
        return result;
    }
};
