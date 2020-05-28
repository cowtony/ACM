class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i >> 1] + i % 2;
            /*
            if (i % 2 == 0) {
                res[i] = res[i / 2];
            } else {
                res[i] = res[i / 2] + 1;
                // res[i] = res[i - 1] + 1;
            }
            */
        }
        return res;
    }
};
