class Solution {
public:
    int kMod = 1000000007;

    int numPrimeArrangements(int n) {
        int primes = countPrimesWithin(n);
        return (factorial(primes) * factorial(n - primes)) % kMod;
    }

    int countPrimesWithin(int n) {
        int count = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                count++;
            }
        }
        return count;
    }

    bool isPrime(int n) {
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int64_t factorial(int n) {
        int64_t result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * i) % kMod;
        }
        return result;
    }
};
