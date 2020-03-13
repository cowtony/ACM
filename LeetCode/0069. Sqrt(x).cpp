class Solution {
public:
    int mySqrt(int x) {
        int lo = 0, hi = INT_MAX - 1;
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
