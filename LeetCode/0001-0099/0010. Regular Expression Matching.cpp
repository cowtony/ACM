class Solution {
public:
    bool isMatch(string s, string p) {
        // s\p  0 c * a * b
        //  0   T F T F T F
        //  a   F F F T T F
        //  a   F F F F T F
        //  b   F F F F F T
        
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;
        
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                
                if (i > 0 and (p[j - 1] == s[i - 1] or p[j - 1] == '.')) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                
                if (p[j - 1] == '*') { 
                    dp[i][j] = dp[i][j - 2]; // j - 2 is garenteed to be valid since p cannot start with '*'.
                    dp[i][j] = dp[i][j] or i > 0 and dp[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == '.');
                }
            }
        }
        
        return dp[s.length()][p.length()];
    }
};
