class Solution {
public:
    int arrangeCoins(int n) {
        // (1 + k) * k / 2 <= n
        // (1 + k) * k / 2 + (k + 1) > n
        int lo = 0, hi = 65536;
        while (lo < hi) {
            uint64_t k = (lo + hi + 1) / 2;
            if ((1 + k) * k / 2 <= n) {
                lo = k;
            } else {
                hi = k - 1;
            }
        }
        return lo;
    }
};
