class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        while (dp.size() <= n) {
            int res = INT_MAX;
            for (int i = 1; i * i <= dp.size(); i++) {
                res = min(res, dp[dp.size() - i * i] + 1);
            }
            
            dp.push_back(res);
        }
        return dp[n];
    }
};
