class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int negative = 0;
        if (dividend < 0) {
            negative++;
        }
        if (divisor < 0) {
            negative++;
        }
        
        long dividend_l = labs(dividend), divisor_l = labs(divisor);
        
        unsigned int m = 1;
        while (divisor_l < int(divisor_l << 1)) {
            cout << divisor_l << " " << (divisor_l << 1) << endl;
            divisor_l <<= 1;
            m <<= 1;
        }
        
        long count = 0;
        while (m > 0) {
            if (dividend_l >= divisor_l) {
                dividend_l -= divisor_l;
                count += m;
            } else {
                divisor_l >>= 1;
                m >>= 1;
            }
        }
            
        return negative == 1? -count : count;
    }
};
