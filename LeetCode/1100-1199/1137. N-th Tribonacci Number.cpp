class Solution {
public:
    int tribonacci(int n) {
        int t_0 = 0, t_1 = 1, t_2 = 1;
        if (n == 0) {
            return 0;
        } else if (n <= 2) {
            return 1;
        }
        for (int i = 3; i <= n; i++) {
            int t_3 = t_0 + t_1 + t_2;
            t_0 = t_1;
            t_1 = t_2;
            t_2 = t_3;
        }
        return t_2;
    }
};