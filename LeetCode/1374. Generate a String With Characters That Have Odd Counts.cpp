class Solution {
public:
    string generateTheString(int n) {
        string s;
        if (n == 0) {
            return "";
        }
        if (n % 2 == 0) {
            return string(n - 1, 'a') + 'b';
        } else {
            return string(n, 'a');
        }
    }
};
