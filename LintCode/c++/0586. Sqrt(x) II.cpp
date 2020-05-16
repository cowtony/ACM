class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        double ans = x;
        while (abs(ans * ans - x) > 1e-11) {
            // Newton’s Method
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};
