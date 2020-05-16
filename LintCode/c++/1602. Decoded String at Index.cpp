class Solution {
public:
    /**
     * @param S: An encoded string.
     * @param K: An index.
     * @return: Return the K-th letter (1 indexed) in the decoded string.
     */
    string decodeAtIndex(string &S, int K) {
        long len = 0;
        int i = 0;
        for (; i < S.length(); i++) {
            if (len > K) {
                break;
            }
            if (S[i] >= '0' and S[i] <= '9') {
                len *= S[i] - '0';
            } else {
                len++;
            }
        }

        for (i--; i >= 0; i--) {
            if (S[i] >= '0' and S[i] <= '9') {
                len /= S[i] - '0';
                K %= len;
            } else {
                if (K == len or K == 0) {
                    return string(1, S[i]);
                }
                len--;
            }
        }

        return "";
    }
};
