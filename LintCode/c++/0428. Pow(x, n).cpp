class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        double result = 1;
        if (n < 0) {
            n = -n - 1;  // prevent n = -2^31
            x = 1 / x;
            result = x;
        }
        
        double base = x;
        while (n > 0) {
            if (n & 1 == 1) {
                result *= base;
            }
            base *= base;
            n >>= 1;
        }
        
        return result;
    }
};
