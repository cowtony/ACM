class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int max_lenth = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                int left = i - dp[i - 1] - 1;
                if (left >= 0) {
                    if (s[left] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (left > 0) {
                            dp[i] += dp[left - 1];
                        }
                    }
                }
            }
            max_lenth = max(max_lenth, dp[i]);
        }
        return max_lenth;
    }
};
