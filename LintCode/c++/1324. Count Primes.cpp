class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
    
        int count = 1;
        for (int i = 3; i < n; i += 2) {
            if (isPrime(i)) {
                count++;
            }
        }
        return count;
    }
    
    bool isPrime(int n) {
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};
