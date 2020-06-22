class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        
        vector<vector<int>> dp(costs.size(), vector<int>(costs[0].size(), 0));
        
        int min_cost = 0, min_color = 0, second_min_cost = 0;
        for (int n = 0; n < costs.size(); n++) {
            for (int k = 0; k < costs[0].size(); k++) {
                dp[n][k] = costs[n][k];
                if (k != min_color) {
                    dp[n][k] += min_cost;
                } else {
                    dp[n][k] += second_min_cost;
                }
            }
            
            min_cost = INT_MAX;
            for (int k = 0; k < costs[0].size(); k++) {
                if (min_cost > dp[n][k]) {
                    min_cost = dp[n][k];
                    min_color = k;
                }
            }
            second_min_cost = INT_MAX;
            for (int k = 0; k < costs[0].size(); k++) {
                if (second_min_cost > dp[n][k] and k != min_color) {
                    second_min_cost = dp[n][k];
                }
            }
        }
        
        int total_min = INT_MAX;
        for (int k = 0; k < dp[0].size(); k++) {
            total_min = min(total_min, dp[costs.size() - 1][k]);
        }
        return total_min;
    }
};
