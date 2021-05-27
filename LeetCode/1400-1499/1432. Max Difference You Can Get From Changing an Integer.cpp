class Solution {
public:
    int maxDiff(int num) {
        int min_a = INT_MAX, max_b = INT_MIN;
        for (int x = 0; x <= 9; x++) {
            for (int y = 0; y <= 9; y++) {
                int a = replace(num, x, y);
                if (x == 1 and y == 9) {
                    cout << a << endl;
                }
                if (a != -1) {
                    min_a = min(min_a, a);
                    max_b = max(max_b, a);
                }
            }
        }
        return max_b - min_a;
    }
    
    int replace(int num, int x, int y) {
        int ret = 0;
        int base = 1;
        int last_digit = 0;
        while (num > 0) {
            last_digit = num % 10;
            if (num % 10 == x) {
                ret += base * y;
            } else {
                ret += base * (num % 10);
                // last_digit = num % 10;
            }
            base *= 10;
            num /= 10;
            
        }
        if (ret == 0 or (last_digit == x and y == 0)) {
            return -1;
        }
        return ret;
    }
};
