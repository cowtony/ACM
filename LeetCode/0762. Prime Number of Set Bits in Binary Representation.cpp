class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int count = 0;
        for (int i = L; i <= R; i++) {
            if (primes.find(__builtin_popcount(i)) != primes.end()) {
                count++;
            }
        }
        return count;
    }
};
