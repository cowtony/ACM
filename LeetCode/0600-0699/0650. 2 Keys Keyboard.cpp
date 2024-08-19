class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        
        int operations = 0;
        int factor = 2;

        while (factor * factor <= n) {
            if (n % factor == 0) {
                operations += factor;
                n /= factor;
            } else {
                factor++;
            }
        }
        return operations + n;
    }
};
