class Solution {
public:
    /**
     * @param S: A string
     * @param T: A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        vector<long> dp(T.length() + 1, 0);
        dp[0] = 1;
        
        for (size_t s = 1; s <= S.length(); s++) {
            for (int t = min(s, T.length()); t > 0; t--) {
                if (T[t - 1] == S[s - 1]) {
                    dp[t] += dp[t - 1];
                }
            }
        }
        
        return dp[T.length()];
    }
};
