class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int s = 0, t = 0; // Counting the '#'.
        
        while (true) {
            while (i >= 0) {
                if (S[i] == '#') {
                    s++;
                    i--;
                } else if (s > 0) {
                    s--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    t++;
                    j--;
                } else if (t > 0) {
                    t--;
                    j--;
                } else {
                    break;
                }
            }
            if (i < 0 or j < 0) {
                return i < 0 and j < 0;
            }
            if (S[i--] != T[j--]) {
                return false;
            }
        }
    }
};
