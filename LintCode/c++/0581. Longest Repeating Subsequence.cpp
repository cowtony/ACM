class Solution {
public:
    /**
     * @param str: a string
     * @return: the length of the longest repeating subsequence
     */
    int longestRepeatingSubsequence(string &str) {
        vector<vector<int>> dp(str.length() + 1, vector<int>(str.length() + 1, 0));
        
        for (int i = 1; i <= str.length(); i++) {
            for (int j = 1; j < i; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (str[i - 1] == str[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        
        return dp[str.length()][str.length() - 1];
    }
};
