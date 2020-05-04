class Solution {
public:
    int findComplement(int num) {
        stack<int> digits;
        while (num > 0) {
            digits.push(num % 2);
            num >>= 1;
        }
        int res = 0;
        while (!digits.empty()) {
            res <<= 1;
            res += 1 - digits.top();
            digits.pop();
        }
        return res;
    }
};
