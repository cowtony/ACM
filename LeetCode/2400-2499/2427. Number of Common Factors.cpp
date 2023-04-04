class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 1;
        for (int i = 2; i <= min(a, b); i++) {
            int count_i = 1;
            while (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
                count_i++;
            }
            count *= count_i;
        }
        
        return count;
    }
};
