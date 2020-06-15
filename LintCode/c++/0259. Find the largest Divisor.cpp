class Solution {
public:
    /**
     * @param A: the array.
     * @param k: the integer.
     * @return: the divisor satisfy the requirement.
     */
    int FindDivisor(vector<int> &A, int k) {
        int lo = 1, hi = 1E9;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (helper(A, mid) < k) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        return lo;
    }
    
    int helper(vector<int> &A, int d) {
        int res = 0;
        for (int a : A) {
            res += (a + d - 1) / d;
        }
        return res;
    }
};
