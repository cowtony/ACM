class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        int count = 1;
        for (int i = 3; i < n; i += 2) {
            if (isPrime(i)) {
                ++count;
            }
        }
        return count;
    }
    
    bool isPrime(int n) {
        if (n < 2) { return false; }
        if (n % 2 == 0) { return n == 2; }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};
