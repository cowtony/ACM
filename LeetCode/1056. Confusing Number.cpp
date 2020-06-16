class Solution {
public:
    bool confusingNumber(int N) {
        unordered_map<int, int> confusing_digits = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        int rotated = 0;
        int n = N;
        while (n) {
            if (confusing_digits.find(n % 10) == confusing_digits.end()) {
                return false;
            }
            rotated = rotated * 10 + confusing_digits[n % 10];
            n /= 10;
        }
        return rotated != N;
    }
};
