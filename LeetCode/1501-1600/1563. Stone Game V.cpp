class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        prefix_sum.push_back(0);
        for (int i = 0; i < stoneValue.size(); i++) {
            prefix_sum.push_back(prefix_sum.back() + stoneValue[i]);
        }
        
        dp = vector<vector<int>>(stoneValue.size() + 1, vector<int>(stoneValue.size() + 1, -1));
        
        return dfs(0, stoneValue.size());
    }
    
    vector<vector<int>> dp;
    vector<int> prefix_sum;
                                 
    int dfs(int start, int end) {
        if (dp[start][end] >= 0) {
            return dp[start][end];
        }
        if (end == start + 1) {
            return dp[start][end] = 0;
        }
        
        for (int i = start + 1; i < end; i++) {
            int left = prefix_sum[i] - prefix_sum[start];
            int right = prefix_sum[end] - prefix_sum[i];
            if (left <= right) {
                dp[start][end] = max(dp[start][end], left + dfs(start, i));
            }
            if (left >= right) {
                dp[start][end] = max(dp[start][end], right + dfs(i, end));
            }
        }
        return dp[start][end];
    }
};
