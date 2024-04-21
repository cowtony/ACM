class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        vector<int> dp(10, 0);
        for (int col = 0; col < grid[0].size(); col++) {
            
            vector<int> count(10, 0);
            for (int row = 0; row < grid.size(); row++) {
                count[grid[row][col]]++;
            }
            
            vector<int> new_dp(10, 0);
            for (int i = 0; i < 10; i++) {
                new_dp[i] = minDp(dp, i) + grid.size() - count[i];
            }
            dp = new_dp;
        }
        
        return minDp(dp, -1);
    }
    
    int minDp(vector<int>& dp, int exclude) {
        int minimum = INT_MAX;
        for (int i = 0; i < dp.size(); i++) {
            if (i == exclude) {
                continue;
            }
            minimum = min(minimum, dp[i]);
        }
        return minimum;
    }
};
