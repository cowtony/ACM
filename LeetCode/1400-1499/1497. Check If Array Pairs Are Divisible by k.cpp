class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainders(k, 0);
        for (int a : arr) {
            remainders[(a % k + k) % k]++;  // Get positive remainder.
        }
        if (remainders[0] % 2 == 1) {
            return false;
        }
        for (int i = 1; i < k; i++) {
            if (remainders[i] != remainders[k - i]) {
                return false;
            }
        }
        return true;
    }
};
