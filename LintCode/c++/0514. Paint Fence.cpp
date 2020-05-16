class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
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
