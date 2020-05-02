class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k == 0 or m < k) {
            return 0;
        }

        vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(m + 1, vector<long>(k + 1, 0)));
        for (int i = 1; i <= m; i++) {
            dp[0][i][1] = 1;
        }
        
        for (int K = 1; K <= k; K++) {
            for (int M = 1; M <= m; M++) {
                for (int N = 1; N < n; N++) {
                    dp[N][M][K] = dp[N - 1][M][K] * M;
                    for (int mm = 1; mm < M; mm++) {
                        dp[N][M][K] = (dp[N][M][K] + dp[N - 1][mm][K - 1]) % 1000000007;
                    }
                }
            }
        }
        
        int ret = 0;
        for (int i = 1; i <= m; i++) {
            ret = (ret + dp[n - 1][i][k]) % 1000000007;
        }
        return ret;
        
    }

};
