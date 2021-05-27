class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0, val = start; i < n; i++, val += 2) {
            res ^= val;
        }
        return res;
    }
};
