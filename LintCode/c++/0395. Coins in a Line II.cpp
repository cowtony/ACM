class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        vector<int> dp(values.size(), 0);
        dp[values.size() - 1] = values.back();
        for (int i = values.size() - 2; i >= 0; i--) {
            if (i < values.size() - 2) {
                dp[i] = max(values[i] - dp[i + 1], values[i] + values[i + 1] - dp[i + 2]);
            } else {
                dp[i] = max(values[i] - dp[i + 1], values[i] + values[i + 1]);
            }
        }
        return dp[0] >= 0;
    }
};
