class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = s[0] > '0'? 1 : 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] > '0' and (s[i - 1] - '0') * 10 + s[i] - '0' <= 26) {
                dp[i] += i >= 2? dp[i - 2] : 1;
            }
            if (s[i] > '0') {
                dp[i] += dp[i - 1];
            }
        }
        return dp[s.length() - 1];
    }
};
