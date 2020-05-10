class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        vector<vector<int>> suffix_sum(pizza.size() + 1, vector<int>(pizza[0].length() + 1, 0));
        for (int r = pizza.size() - 1; r >= 0; r--) {
            for (int c = pizza[0].size() - 1; c >= 0; c--) {
                suffix_sum[r][c] = suffix_sum[r + 1][c] 
                                 + suffix_sum[r][c + 1] 
                                 - suffix_sum[r + 1][c + 1] 
                                 + (pizza[r][c] == 'A'? 1 : 0);
            }
        }
        
        vector<vector<vector<int>>> dp(pizza.size() + 1, vector<vector<int>>(pizza[0].length() + 1, vector<int>(k, 0)));
        for (int row = dp.size() - 1; row >= 0; row--) {
            for (int col = dp[0].size() - 1; col >= 0; col--) {
                dp[row][col][0] = suffix_sum[row][col] > 0 ? 1 : 0;
            }
        }
        for (int cut = 1; cut < k; cut++) {
            for (int row = dp.size() - 1; row >= 0; row--) {
                for (int col = dp[0].size() - 1; col >= 0; col--) {
                    for (int r = row + 1; r < dp.size(); r++) {
                        if (suffix_sum[r][col] == 0) {
                            break;
                        }
                        if (suffix_sum[row][col] - suffix_sum[r][col] > 0) {
                            dp[row][col][cut] = (dp[row][col][cut] + dp[r][col][cut - 1]) % 1000000007;
                        }
                    }
                    for (int c = col + 1; c < dp[0].size(); c++) {
                        if (suffix_sum[row][c] == 0) {
                            break;
                        }
                        if (suffix_sum[row][col] - suffix_sum[row][c] > 0) {
                            dp[row][col][cut] = (dp[row][col][cut] + dp[row][c][cut - 1]) % 1000000007;
                        }
                    }
                }
            }
        }

        return dp[0][0][k - 1];
    }
};
