class Solution {
public:
    /**
     * @param n: the integer to be reversed
     * @return: the reversed integer
     */
    int reverseInteger(int x) {
        int sign = 1;
        
        int64_t y = x;
        if (y < 0)
        {
            sign = -1;
            y = -y;
        }
        
        long long result = 0;
        while (y)
        {
            result = result * 10 + y % 10;
            y /= 10;
        }
        
        if (result >= 0x80000000)
            return 0;
        else
            return sign * result;
    }
};
