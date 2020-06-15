class Solution {
public:
    /**
     * @param a: A number
     * @return: Returns the maximum number after insertion
     */
     
    // Example: a = 234, base = 100, return = 2534
    int insertFiveFrom(int a, int base) {
        return a % base + a / base * base * 10 + 5 * base;
    }
    
    int InsertFive(int a) {
        if (a == 0) {
            return 50;
        } else if (a > 0) {
            int base = 10000000;
            while (base / 10 > a or (base > 1 and a / (base / 10) % 10 >= 5)) {
                base /= 10;
            }
            return insertFiveFrom(a, base);
        } else { // a < 0
            a = -a;
            int base = 10000000;
            while (base / 10 > a or (base > 1 and a / (base / 10) % 10 < 5)) { // Should be <= 5
                base /= 10;
            }
            return -insertFiveFrom(a, base);
        }
    }
};
