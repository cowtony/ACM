class Solution {
public:
    /**
     * @param target: the destination
     * @return: the minimum number of steps
     */
    int reachNumber(int target) {
        target = abs(target);
        int n = ceil((sqrt(1 + 8.0 * target) - 1) / 2.0); // ((1 + n) * n) / 2 >= target
        int sum = (1 + n) * n / 2;

        if ((sum - target) % 2 == 0) {
            return n; // just flip + sign to - of the number diff / 2.
        } else if (n % 2 == 0) {
            return n + 1; // - n + (n + 1) = 1
        } else {
            return n + 2; // - (n + 1) + (n + 2) = 1
        }
    }
};
