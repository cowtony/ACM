// For any merge sequence, such as (a - (b - c) - d) = a - b + c - d = (b + c) - (a + d)
// Can always rewrite to the difference of the sum of two groups.
// The problem become 0-1 knapsack.
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int capacity = sum / 2;

        vector<bool> dp(capacity + 1, false);  // or use bitset<1501>
        dp[0] = true;

        for (int stone : stones) {
            for (int i = capacity; i >= stone; i--) {
                dp[i] = dp[i] || dp[i - stone];
            }
        }
        for (int i = capacity; i >= 0; i--) {
            if (dp[i] == true) {
                return sum - 2 * i;
            }
        }
        return 0;
    }
};
