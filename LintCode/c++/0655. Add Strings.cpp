class Solution {
public:
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        string ret;
        int idx1 = num1.length() - 1;
        int idx2 = num2.length() - 1;
        int carry = 0;
        while (idx1 >= 0 or idx2 >= 0 or carry > 0) {
            int x1 = 0;
            int x2 = 0;
            if (idx1 >= 0) {
                x1 = num1[idx1] - '0';
                idx1--;
            }
            if (idx2 >= 0) {
                x2 = num2[idx2] - '0';
                idx2--;
            }
            ret += (x1 + x2 + carry) % 10 + '0';
            carry = (x1 + x2 + carry) / 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
