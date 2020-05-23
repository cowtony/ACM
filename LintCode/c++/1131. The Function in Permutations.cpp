class Solution {
public:
    /**
     * @param n: An integer.
     * @return: Return [minF(n), maxF(n)].
     */
    vector<int> minMax(int n) {
        // n = 1: {1, 1}
        // n = 2: {1, 1}
        // n = 3: {0, 2}
        // n = 4: {0, 4}
        // n = 5: {1, 5}
        // n = i: F(i)min = int(((i + 1) % 4) / 2)
        // n = i: F(i)max = i - F(i - 1)min = i - int((i % 4) / 2)
        return {(n + 1) % 4 / 2, n - (n % 4) / 2};
    }
};
