class Solution {
public:
    long long distributeCandies(int n, int limit) {
        return C(n + 2, 2)  // Insert 2 boards to n + 2 slots, +2 to allow zero allocation.
             - 3 * C(n + 2 - (limit + 1), 2)
             + 3 * C(n + 2 - (limit + 1) * 2, 2)
             - C(n + 2 - (limit + 1) * 3, 2);
    }

    uint64_t C(int total, int pick) {
        if (total < 0 || pick < 0 || pick > total) {
            return 0;
        } else if (pick > total - pick) {
            return C(total, total - pick);
        }

        uint64_t result = 1;
        for (int i = total, j = 1; j <= pick; --i, ++j) {
            result *= i;
            result /= j;
        }
        return result;
    }
};
