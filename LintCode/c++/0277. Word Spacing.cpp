class Solution {
public:
    /**
     * @param words: the words given.
     * @param wordA: the first word you need to find.
     * @param wordB: the second word you need to find.
     * @return: return the spacing of the closest wordA and wordB.
     */
    int wordSpacing(vector<string> &words, string &wordA, string &wordB) {
        int last_a = -1, last_b = -1;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == wordA) {
                last_a = i;
                if (last_b >= 0) {
                    res = min(res, last_a - last_b);
                }
            } else if (words[i] == wordB) {
                last_b = i;
                if (last_a >= 0) {
                    res = min(res, last_b - last_a);
                }
            }
        }
        return res == INT_MAX? -1 : res;
    }
};
