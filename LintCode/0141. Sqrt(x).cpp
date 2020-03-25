// LeetCode 69: https://leetcode.com/problems/sqrtx/
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        int lo = 0, hi = x;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (mid > x / mid) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        } 
        return lo;
    }
};
