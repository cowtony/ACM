class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // dp[i][len] means if the sub-game is piles from `i` with length `len`, first player will be winning how much.
        vector<vector<int>> dp(values.size(), vector<int>(values.size() + 1, 0));
        
        for (int len = 1; len <= values.size(); len++) {
            for (int i = 0; i + len <= values.size(); i++) {
                if (i + 1 < values.size()) {
                    dp[i][len] = max(values[i] - dp[i + 1][len - 1], values[i + len - 1] - dp[i][len - 1]);
                } else {
                    dp[i][len] = values[i + len - 1] - dp[i][len - 1];
                }
            }
        }
        return dp[0][values.size()] >= 0;
    }
};
