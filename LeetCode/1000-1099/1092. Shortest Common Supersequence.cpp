class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Longest Common Subsequence
        vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1));
        for (int i = 0; i < str1.length(); ++i) {
            for (int j = 0; j < str2.length(); ++j) {
                if (str1[i] == str2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        string result;
        int i = str1.length(), j = str2.length();
        while (i > 0 && j > 0) {
            if (dp[i][j] == dp[i - 1][j]) {
                result += str1[--i];
            } else if (dp[i][j] == dp[i][j - 1]) {
                result += str2[--j];
            } else {
                --i, --j;
                result += str1[i];  // str1[i] must == str2[j]
            }
        }
        return str1.substr(0, i) + str2.substr(0, j) + string(result.rbegin(), result.rend());
    }
};
