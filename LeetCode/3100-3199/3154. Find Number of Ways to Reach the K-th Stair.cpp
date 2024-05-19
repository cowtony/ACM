class Solution {
public:
    int waysToReachStair(int k) {
        int result = 0;
        for (int op2 = 1, op2_sum = 1; op2_sum - k <= op2; op2++, op2_sum *= 2) {
            result += C(op2, op2_sum - k);
        }
        return result;
    }
    
    int C(int a, int b) {
        if (b > a || b < 0) {
            return 0;
        }
        
        long long result = 1;
        for (int i = a, j = 1; j <= b; i--, j++) {
            result *= i;
            result /= j;
        }
        return result;
    }
};
