class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        if (k >= houses.size()) {
            return 0;
        }
        sort(houses.begin(), houses.end());
        
        // Best way to place 1 mailbox for a set of houses is to place at the house that sits in the middle.
        // cost[i][j] means the total cost of placing 1 mailbox for house i to j.
        vector<vector<int>> cost(houses.size(), vector<int>(houses.size(), INT_MAX));
        for (int center = 0; center < houses.size(); center++) {
            int sum_cost = 0;
            for (int i = 0; center - i >= 0 and center + i < houses.size(); i++) {
                sum_cost += houses[center] - houses[center - i];
                cost[center - i][center + i] = sum_cost;
                if (center + i + 1 < houses.size()) {
                    sum_cost += houses[center + i + 1] - houses[center];
                    cost[center - i][center + i + 1] = sum_cost;
                }
            }
        }
        
        vector<vector<int>> dp(k + 1, vector<int>(houses.size() + 1, INT_MAX >> 1));
        dp[0][0] = 0;
        for (int K = 1; K <= k; K++) {
            for (int i = K; i <= houses.size(); i++) {
                for (int x = K - 1; x < i; x++) {
                    dp[K][i] = min(dp[K][i], dp[K - 1][x] + cost[x][i - 1]);
                }
            }
        }

        return dp[k][houses.size()];
    }
};
