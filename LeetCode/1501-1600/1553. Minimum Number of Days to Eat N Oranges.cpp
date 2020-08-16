class Solution {
public:
    int minDays(int n) {
        static unordered_map<int, int> dp;
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        if (n <= 2) {
            return dp[n] = n;
        }
        return dp[n] = min(minDays(n / 3) + n % 3, minDays(n / 2) + n % 2) + 1;
    }
};
