class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        vector<vector<vector<bool>>> dp(s1.length(), vector<vector<bool>>(s2.length(), vector<bool>(s1.length() + 1, false)));
        
        for (int len = 1; len <= s1.length(); len++) {
            for (int i = 0; i + len <= s1.length(); i++) {
                for (int j = 0; j + len <= s2.length(); j++) {
                    if (s1.substr(i, len) == s2.substr(j, len)) {
                        dp[i][j][len] = true;
                        continue;
                    }
                    for (int k = 1; k < len; k++) {
                        if (dp[i][j][len] = dp[i][j + len - k][k] and dp[i + k][j][len - k] 
                                            or dp[i][j][k] and dp[i + k][j + k][len - k]) {
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][s1.length()];
    }
};
