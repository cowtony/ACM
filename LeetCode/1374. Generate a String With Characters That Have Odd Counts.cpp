class Solution {
public:
    string generateTheString(int n) {
        string s;
        if (n == 0) {
            return "";
        }
        if (n % 2 == 0) {
            for (int i = 0; i < n - 1; i++) {
                s += 'a';
            }
            return s + 'b';
        } else {
            for (int i = 0; i < n; i++) {
                s += 'a';
            }
            return s;
        }
    }
};
