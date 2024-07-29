class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> result;
        for (int i = 0; i < variables.size(); i++) {
            if (helper(variables[i][0], variables[i][1], variables[i][2], variables[i][3], target)) {
                result.push_back(i);
            }
        }
        return result;
    }

    bool helper(int a, int b, int c, int m, int target) {
        return pow(pow(a, b, 10), c, m) == target;
    }

    // Calculate `(x ^ y) % mod` by converting the y into binary bits.
    int pow(int x, int y, int mod) {
        if (y <= 0) {
            return 1 % mod;
        }
        x %= mod;
        int result = 1;
        while (y) {
            if (y & 1) {
                result = multiply(result, x, mod);
            }
            x = multiply(x, x, mod);
            y >>= 1;
        }
        return result;
    }

    int multiply(int x, int y, int mod) {
        return ((x % mod) * (y % mod)) % mod;
    }
};
