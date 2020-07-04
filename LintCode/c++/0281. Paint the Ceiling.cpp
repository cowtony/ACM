class Solution {
public:
    /**
     * @param s0: the number s[0]
     * @param n: the number n
     * @param k: the number k
     * @param b: the number b
     * @param m: the number m
     * @param a: area
     * @return: the way can paint the ceiling
     */
    long long painttheCeiling(int s0, int n, int k, int b, int m, long long a) {
        vector<int> ss(n);
        for (int i = 0; i < n; i++) {
            ss[i] = s0;
            s0 += (s0 * (long long)k + b) % m + 1;
        }
    
        int lo = 0;
        long long res = 0;
        for (int hi = ss.size() - 1; hi >= 0; hi--) {
            while (lo < ss.size() and ss[lo] * (long long)ss[hi] <= a) {
                lo++;
            }
            res += lo;
        }
        return res;
    }    
};
