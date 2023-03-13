class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int kMod = 1000000007;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> dp;
        int result = 0;
        for(int num : arr) {
            dp[num] = 1;
            for (const auto& [n, count] : dp) {
                if (num % n == 0 && dp.count(num / n) > 0) {
                    dp[num] = (dp[num] + int64_t(dp[n]) * dp[num / n]) % kMod;
                }
            }
            result = (result + dp[num]) % kMod;
        }
        return result;
    }
};
