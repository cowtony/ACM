class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 and (num & (num - 1)) == 0 and (num - 1) % 3 == 0;
    }
};
