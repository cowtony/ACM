class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int count_x1 = 0, count_y1 = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x') {
                    count_x1++;
                } else {
                    count_y1++;
                }
            }
        }
        if ((count_x1 + count_y1) % 2 == 1) {
            return -1;
        }
        return count_x1 + count_y1 - count_x1 / 2 - count_y1 / 2;
    }
};