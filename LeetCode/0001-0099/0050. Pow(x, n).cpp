class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        if (n < 0) {
            n = -1 - n;  // prevent n = -2^31
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
