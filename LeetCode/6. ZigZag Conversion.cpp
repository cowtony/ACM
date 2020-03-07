class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int c = (numRows - 1) * 2;
        string ret;
        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < s.length(); i += c) {
                ret += s[i];
                if (row > 0 and row < numRows - 1 and i + c - row * 2 < s.length()) {
                    ret += s[i + c - row * 2];
                }
            }
        }
        return ret;
    }
};
