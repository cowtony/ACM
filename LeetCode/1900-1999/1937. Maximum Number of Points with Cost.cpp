class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> dp{points[0].begin(), points[0].end()};

        for (int i = 1; i < points.size(); i++) {
            vector<long long> temp_dp = dp;

            long long maximum = -1e8;
            for (int j = 0; j < dp.size(); j++) {
                maximum = max(maximum, dp[j]);
                temp_dp[j] = max(temp_dp[j], points[i][j] + maximum);
                maximum--;
            }
            maximum = -1e8;
            for (int j = dp.size() - 1; j >= 0; j--) {
                maximum = max(maximum, dp[j]);
                temp_dp[j] = max(temp_dp[j], points[i][j] + maximum);
                maximum--;
            }

            dp = temp_dp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
