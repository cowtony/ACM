class Solution {
public:
    using LL = long long;
    const int kMod = 1000000007;

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }

        LL maximum = 0;
        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> min_heap;
        for (int i = 0; i < nums.size(); i++) {
            min_heap.push({nums[i], i});
            maximum = max(LL(nums[i]), maximum);
        }

        while (k) {
            auto [val, idx] = min_heap.top();
            if (val * multiplier > maximum) {
                break;
            }

            min_heap.pop();
            min_heap.push({val * multiplier, idx});
            k--;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto [val, idx] = min_heap.top();
            min_heap.pop();

            if (i < k % nums.size()) {
                nums[idx] = multiply(val, pow(multiplier, k / nums.size() + 1, kMod), kMod);
            } else {
                nums[idx] = multiply(val, pow(multiplier, k / nums.size(), kMod), kMod);
            }   
        }

        return nums;
    }

    int multiply(LL x, LL y, int mod) {
        return ((x % mod) * (y % mod)) % mod;
    }

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
};
