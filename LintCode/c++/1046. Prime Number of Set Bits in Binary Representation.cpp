class Solution {
public:
    /**
     * @param L: an integer
     * @param R: an integer
     * @return: the count of numbers in the range [L, R] having a prime number of set bits in their binary representation
     */
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
