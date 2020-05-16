class Solution {
public:
    /**
     * @param n: An integer
     * @param times: an array of integers
     * @return: an integer
     */
    int copyBooksII(int n, vector<int> &times) {
        int lo = 1, hi = times[0] * n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (possible(n, times, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    bool possible(int n, vector<int> &times, int time_limit) {
        int count = 0;
        for (int t : times) {
            count += time_limit / t;
        }
        return count >= n;
    }
};
