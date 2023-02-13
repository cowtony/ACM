class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<int> r_idx(256), c_idx(256);
        for (char c = 'a'; c <= 'z'; c++) {
            r_idx[c] = (c - 'a') / 5;
            c_idx[c] = (c - 'a') % 5;
        }

        string result;
        int row = 0, col = 0;
        for (char c : target) {
            if (col > c_idx[c]) {
                result += string(col - c_idx[c], 'L');
                col = c_idx[c];
            }
            if (row > r_idx[c]) {
                result += string(row - r_idx[c], 'U');
                row = r_idx[c];
            }
            if (col < c_idx[c]) {
                result += string(c_idx[c] - col, 'R');
                col = c_idx[c];
            }
            if (row < r_idx[c]) {
                result += string(r_idx[c] - row, 'D');
                row = r_idx[c];
            }
            result += '!';
        }
        return result;
    }
};
