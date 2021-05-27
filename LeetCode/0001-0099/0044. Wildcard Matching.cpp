class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] means is s.substr(0, i) matches p.substr(0, j).
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;
        for (int i = 0; p[i] == '*' and i < p.length(); i++) {
            dp[0][i + 1] = true;
        }
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - 1] or dp[i][j - 1];
                }
                else if (p[j - 1] == '?' or s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
