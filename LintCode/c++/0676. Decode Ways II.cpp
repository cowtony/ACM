class Solution {
public:
    /**
     * @param s: a message being encoded
     * @return: an integer
     */
    int numDecodings(string &s) {
        if (s.empty()) {
            return 0;
        }
        vector<uint64_t> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            // One digit:
            if (s[i] == '*') {
                dp[i + 1] += 9 * dp[i];
            } else if (s[i] > '0') {
                dp[i + 1] += dp[i];
            }
            // Two digits:
            if (i == 0) {
                continue;
            }
            switch (s[i - 1]) {
                case '0':
                    break;
                case '1':
                    if (s[i] == '*') {
                        dp[i + 1] += 9 * dp[i - 1];
                    } else {
                        dp[i + 1] += dp[i - 1];
                    }
                    break;
                case '2':
                    if (s[i] == '*') {
                        dp[i + 1] += 6 * dp[i - 1];
                    } else if (s[i] >= '0' and s[i] <= '6') {
                        dp[i + 1] += dp[i - 1];
                    }
                    break;
                case '*':
                    if (s[i] == '*') {
                        dp[i + 1] += 15 * dp[i - 1];
                    } else if (s[i] >= '0' and s[i] <= '6') {
                        dp[i + 1] += 2 * dp[i - 1];
                    } else {
                        dp[i + 1] += dp[i - 1];
                    }
            }
        }
        return dp[s.length()] % 1000000007;
    }
};
