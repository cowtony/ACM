class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        
        dp[0][0] = true;
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i > 0 and dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = true;
                }
                if (j > 0 and dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
