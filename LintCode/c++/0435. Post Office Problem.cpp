class Solution {
public:
    /**
     * @param A: an integer array
     * @param k: An integer
     * @return: an integer
     */
    int postOffice(vector<int> &A, int k) {
        if (k >= A.size()) {
            return 0;
        }
        sort(A.begin(), A.end());
        vector<vector<int>> cost(A.size(), vector<int>(A.size(), INT_MAX));
        for (int center = 0; center < A.size(); center++) {
            int sum_cost = 0;
            for (int i = 0; center - i >= 0 and center + i < A.size(); i++) {
                sum_cost += A[center] - A[center - i];
                cost[center - i][center + i] = sum_cost;
                if (center + i + 1 < A.size()) {
                    sum_cost += A[center + i + 1] - A[center];
                    cost[center - i][center + i + 1] = sum_cost;
                }
            }
        }
        
        vector<vector<int>> dp(k + 1, vector<int>(A.size() + 1, INT_MAX));
        for (int K = 1; K <= k; K++) {
            for (int i = K; i <= A.size(); i++) {
                if (K == 1) {
                    dp[K][i] = cost[0][i - 1];
                    continue;
                }
                dp[K][i] = INT_MAX;
                for (int x = K - 1; x < i; x++) {
                    dp[K][i] = min(dp[K][i], dp[K - 1][x] + cost[x][i - 1]);
                }
            }
        }

        return dp[k][A.size()];
    }
};
