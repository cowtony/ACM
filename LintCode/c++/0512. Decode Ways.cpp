class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 and s[i - 1] > '0' and (s[i - 1] - '0') * 10 + s[i] - '0' <= 26) {
                dp[i + 1] += i >= 2? dp[i - 1] : 1;
            }
            if (s[i] > '0') {
                dp[i + 1] += dp[i];
            }
        }
        return dp[s.length()];
    }
};
