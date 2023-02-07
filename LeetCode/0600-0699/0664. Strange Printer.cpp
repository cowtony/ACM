class Solution {
public:
    int strangePrinter(string s) {
        dp = vector<vector<int>>(s.length() + 1, vector<int>(s.length() + 1, INT_MAX));
        return dfs(s, 0, s.length() - 1);
    }

    int dfs(const string& s, int begin, int end) {
        if (dp[begin][end] != INT_MAX) {
            return dp[begin][end];
        }
        if (begin > end) {
            return dp[begin][end] = 0;
        }
        if (begin == end) {
            return dp[begin][end] = 1;
        }

        dp[begin][end] = 1 + dfs(s, begin + 1, end);
        for (int i = begin + 1; i <= end; i++) {
            if (s[begin] == s[i]) {
                dp[begin][end] = min(dp[begin][end], dfs(s, begin, i - 1) + dfs(s, i + 1, end));
            }
        }
        return dp[begin][end];
    }

    vector<vector<int>> dp;
};