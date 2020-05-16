class Solution {
public:
    /**
     * @param k: integer k
     * @return: minimum number of operations that change 0 to k
     */
    int numberChange(int k) {
        int res = 0;
        while (k > 0) {
            if (k % 2 == 1) {
                res++;
                k--;
            } else {
                res++;
                k >>= 1;
            }
        }
        return res;
    }
};
