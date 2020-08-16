class Solution {
public:
    int nthUglyNumber(int n) {
        // 5, 3, 2          n_5, n_3, n_2
        // 0  0  0 : 1       0    0    0
        // 0, 0, 1 : 2       0    0    1
        // 0, 1, 0 : 3       0    1    1
        // 0, 0, 2 : 4       0    1    2
        // 1, 0, 0 : 5       1    1    2
        // 0, 1, 1 : 6       1    2    3
        // 0, 0, 3 : 8       1    2    4
        // 0, 2, 0 : 9       1    3    4
        // 1, 0, 1 : 10      2    3    4
        int n_2 = 0, n_3 = 0, n_5 = 0;
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            res[i] = min({res[n_2] * 2, res[n_3] * 3, res[n_5] * 5});
            if (res[i] == res[n_2] * 2) {
                n_2++;
            }
            if (res[i] == res[n_3] * 3) {
                n_3++;
            }
            if (res[i] == res[n_5] * 5) {
                n_5++;
            }
        }
        return res[n - 1];
    }
};
