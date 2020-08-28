// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        base_7 /= 10;
        while (base_7 < 100000000) {
            base_7 = base_7 * 7 + (rand7() - 1);
        }
        return base_7 % 10 + 1;
    }

private:
    int base_7 = 0;
};
