class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long low = 0, high = 1e15;

        while (low < high) {
            long long mid = low + (high - low + 1) / 2;
            if (getSumPrice(mid, x) > k) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        return low;
    }

    long long getSumPrice(long long num, int x) {
        long long result = 0;
        for (int i = x - 1; (1LL << i) <= num; i += x) {
            result += countIthBitsUnder(num + 1, i);
        }
        return result;
    }

    long long countIthBitsUnder(long long num, int i) {
        return (num >> i + 1 << i) + max(0LL, (num & (1LL << i + 1) - 1) - (1LL << i));
    }
};
