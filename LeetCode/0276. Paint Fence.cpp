class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) {
            return 0;
        }
        int aa = 0;
        int ab = k;
        for (int i = 2; i <= n; i++) {
            int next_ab = aa * (k - 1) + ab * (k - 1);
            int next_aa = ab;
            aa = next_aa;
            ab = next_ab;
        }
        return aa + ab;
    }
};
