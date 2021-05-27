class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        if (K == 0) {
            int base = (pow(10, N) - 1) / 9;
            vector<int> res;
            for (int i = 1; i <= 9; i++) {
                res.push_back(base * i);
            }
            return res;
        }
        
        // dp[n][i] = all solution with length n ending with digit i.
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(10));
        for (int i = 1; i < 10; i++) {
            dp[1][i] = {i};
        }
        
        for (int n = 2; n <= N; n++) {
            for (int i = 0; i < 10; i++) {
                if (i - K >= 0) {
                    dp[n][i].insert(dp[n][i].end(), dp[n - 1][i - K].begin(), dp[n - 1][i - K].end());
                }
                if (i + K < 10) {
                    dp[n][i].insert(dp[n][i].end(), dp[n - 1][i + K].begin(), dp[n - 1][i + K].end());
                }
                for (int& num : dp[n][i]) {
                    num = num * 10 + i;
                }
            }
        }
        
        vector<int> res;
        for (int i = 0; i <= 9; i++) {
            res.insert(res.end(), dp[N][i].begin(), dp[N][i].end());
        }
        return res;
    }
};
