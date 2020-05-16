class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame2(vector<int> &A) {
        if (A.empty()) {
            return 0;
        }
        vector<int> sum(A.size() * 2 + 1, 0);
        for (int i = 0; i < A.size() * 2; i++) {
            sum[i + 1] = sum[i] + A[i % A.size()];
        }
        
        vector<vector<int>> dp(A.size() * 2, vector<int>(A.size() * 2 + 1, 0));
        for (int len = 2; len <= A.size() * 2; len++) {
            for (int i = 0; i + len <= A.size() * 2; i++) {
                dp[i][len] = INT_MAX;
                for (int k = 1; k < len; k++) {
                    dp[i][len] = min(dp[i][len], dp[i][k] + dp[i + k][len - k]);
                }
                dp[i][len] += sum[i + len] - sum[i];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < A.size(); i++) {
            ans = min(ans, dp[i][A.size()]);
        }
        return ans;
    }
};
