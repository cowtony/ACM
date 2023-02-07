class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // Find how many odd factors of N.
        // N = (x + 1) + ... + (x + k) = kx + (1 + k) * k / 2
        // 2N = 2kx + k + kk = k (2x + k + 1), one of the term is odd.
        while (n % 2 == 0) {
            n /= 2;
        }
        int result = 1;
        for (int i = 3; i * i <= n; i += 2) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            result *= count + 1;
        }
        return n == 1? result : result * 2;
    }

    int consecutiveNumbersSum2(int n) {
        int count = 0;
        for (int i = 1; (1 + i) * i <= n * 2; i++) {
            if (i % 2 == 1) {  // odd
                if (n % i == 0) {
                    count++;
                    cout << i<<' ';
                }
            } else {  // even
                if (n % (i / 2) == 0 && n / (i / 2) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};