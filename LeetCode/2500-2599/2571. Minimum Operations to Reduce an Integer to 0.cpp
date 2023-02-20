class Solution {
public:
    int minOperations(int n) {
        int ops = 0;
        int continious_one = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                continious_one++;
            } else { // == 0
                if (continious_one == 1) {
                    ops++;
                    continious_one = 0;
                } else if (continious_one > 1) {
                    ops++;
                    continious_one = 1;
                }
            }
            n >>= 1;
        }
        if (continious_one > 1) {
            ops += 2;
        } else if (continious_one == 1) {
            ops++;
        }
        return ops;
    }
};
