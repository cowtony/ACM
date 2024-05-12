using LL = long long;

class Solution {
public:

    vector<int> findProductsOfElements(vector<vector<LL>>& queries) {
        //  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
        // [1, 2, 1, 2, 4, 1, 4, 2, 4, 1, 2, 4, 8, 1, 8, ...]  (2 ^ bit)
        //  -  -  ----  -  ----  ----  -------  -  ----
        // [0, 1, 0, 1, 2, 0, 2, 1, 2, 0, 1, 2, 3, 0, 3, ...]  (bit)
        //  -  -  ----  -  ----  ----  -------  -  ----
        //  1  2   3    4   5     6       7     8

        vector<int> result;
        for (const auto& query : queries) {
            vector<LL> count_1 = countBitsTillIndex(query[0]);
            vector<LL> count_2 = countBitsTillIndex(query[1] + 1);

            LL sum_power = 0;
            for (LL bit = 0, power = 1; bit < kMaxBit; bit++, power <<= 1) {
                sum_power += bit * (count_2[bit] - count_1[bit]);
            }
            result.push_back(pow(2, sum_power, query[2]));
        }

        return result;
    }

private:
    const int kMaxBit = 50;

    // Count the bits for all numbers from 1 to `value - 1`.
    // Return the bit count and their sum.
    pair<vector<LL>, LL> countBitsBeforeValue(LL value) {
        vector<LL> count(kMaxBit, 0);
        LL sum_bits = 0;
        for (LL bit = 0, power = 1; bit < kMaxBit; bit++, power <<= 1) {
            LL cur = (value >> (bit + 1)) << bit;
            cur += max(0LL, (value % (power << 1)) - power);
            sum_bits += cur;
            count[bit] = cur;
        }
        return {count, sum_bits};
    }

    LL getValueFromIndex(LL index) {
        index++;
        LL low = 1, high = 1LL << kMaxBit;

        while (low < high) {
            LL mid = low + (high - low) / 2;
            if (countBitsBeforeValue(mid + 1).second < index) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    vector<LL> countBitsTillIndex(LL index) {
        LL value = getValueFromIndex(index);
        auto [count, sum_bits] = countBitsBeforeValue(value);
        // Also include the last value's partial bits.
        if (sum_bits < index) {  
            int bit = 0;
            while (sum_bits < index) {
                count[bit++] += value & 1;
                sum_bits += value & 1;
                value >>= 1;
            }
        }
        for (LL c : count) {
            cout << c << ' ';
        }
        cout << endl;
        return count;
    }

    // Calculate `(x ^ y) % mod` by converting the y into binary bits.
    int pow(LL x, LL y, int mod) {
        if (y <= 0) {
            return 1 % mod;
        }
        x %= mod;
        LL result = 1;
        while (y) {
            if (y & 1) {
                result = multiply(result, x, mod);
            }
            x = multiply(x, x, mod);
            y >>= 1;
        }
        return result;
    }

    int multiply(LL x, LL y, int mod) {
        return ((x % mod) * (y % mod)) % mod;
    }
};
