class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(20, -1)));
        return dfs(rollMax, 1, 0, n, dp);
    }

    int dfs(const vector<int>& rollMax, int num, int times, int n, vector<vector<vector<int>>>& dp) {
        if (dp[n][num][times] != -1) {
            return dp[n][num][times];
        }
        if (n == 0) {
            return dp[n][num][times] = 1;
        }
        int result = 0;
        for (int i = 0; i < 6; i++) {
            if (num != i) {
                result = (result + dfs(rollMax, i, 1, n - 1, dp)) % 1000000007;
            } else if (times < rollMax[i]) {
                result = (result + dfs(rollMax, i, times + 1, n - 1, dp)) % 1000000007;
            }
        }
        return dp[n][num][times] = result;
    }
};
