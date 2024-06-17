class Solution {
public:
    bool judgeSquareSum(int c) {
        for (unsigned long a = 0, b = sqrt(c); a <= b; a++) {
            while (a * a + b * b > c) {
                b--;
            }
            if (a * a + b * b == c) {
                return true;
            }
        }

        return false;
    }
};
