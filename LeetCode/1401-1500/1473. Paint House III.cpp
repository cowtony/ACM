class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 2, vector<int>(n + 1, INT_MAX / 10)));
        dp[0][0][0] = 0;
        
        for(int i = 1; i <= m; i++) {
            for(int t = 0; t <= i and t <= target; t++) {
                for(int c = 0; c <= n; c++) {
                    if(houses[i - 1] == 0) {
                        for(int l = 1; l <= n; l++) {
                            if (c == l) {
                                dp[i][t][l] = min(dp[i][t][l], dp[i - 1][t][c] + cost[i - 1][l - 1]);
                            } else {
                                dp[i][t + 1][l] = min(dp[i][t + 1][l], dp[i - 1][t][c] + cost[i - 1][l - 1]);
                            }
                        }
                    } else if (houses[i - 1] == c) {
                        dp[i][t][houses[i - 1]] = min(dp[i][t][houses[i - 1]], dp[i - 1][t][c]);  
                    } else {
                        dp[i][t + 1][houses[i - 1]] = min(dp[i][t + 1][houses[i - 1]], dp[i - 1][t][c]); 
                    }
                }
            }   
        }
            
        int res = INT_MAX / 10;
        for(int c = 1; c <= n; c++) {
            res = min(res, dp[m][target][c]);
        }
        return res == INT_MAX / 10? -1 : res;
    }

};
