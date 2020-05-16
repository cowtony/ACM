class Solution {
public:
    /**
     * @param n: an unsigned integer
     * @return: the number of â€™1' bits
     */
    int hammingWeight(unsigned int n) {
        int result = 0;
        while (n)
        {
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};
