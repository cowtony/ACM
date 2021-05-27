/*
  ~  b  a  g
~ 1  0  0  0
b 1  1
a 1  1  1
b 1 [2] 1  0
g 1 [2] 1  1  <- not equal, dp[i][j] = dp[i - 1][j]
b 1  3  1  1
a 1  3 [4][1]
g 1  3  4 [5] <- equal, dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
Traverse from top-down, right to left will save 1 dimention.
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long> dp(t.length() + 1, 0);
        dp[0] = 1;
        
        for (size_t S = 1; S <= s.length(); S++) {
            for (int T = min(S, t.length()); T > 0; T--) {
                if (t[T - 1] == s[S - 1]) {
                    dp[T] += dp[T - 1];
                }
            }
        }
        
        return dp[t.length()];
    }
};
