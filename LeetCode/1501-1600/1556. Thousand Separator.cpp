class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) {
            return "0";
        }
        string res;
        int count = 0;
        while (n) {
            if (count > 0 and count % 3 == 0) {
                res = "." + res;
            }
            res = char((n % 10) + '0') + res;
            n /= 10;
            count++;
        }
        return res;
    }
};
