class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) {
            return 0;
        }
        
        vector<bool> eratosthenes_sieve(n, true);
        eratosthenes_sieve[0] = eratosthenes_sieve[1] = false;
        
        for (int factor = 2; factor * factor < n; factor++) {
            if (!eratosthenes_sieve[factor]) {
                continue;
            }
            for (int multiple = factor * 2; multiple < n; multiple += factor) {
                eratosthenes_sieve[multiple] = false;
            }
        }

        return std::count(eratosthenes_sieve.begin(), eratosthenes_sieve.end(), true);
    }
};
