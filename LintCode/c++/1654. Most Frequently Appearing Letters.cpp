class Solution {
public:
    /**
     * @param str: the str
     * @return: the sum that the letter appears the most
     */
    int mostFrequentlyAppearingLetters(string &str) {
        map<char, int> m;
        for (char c : str) {
            m[c]++;
        }
        int max_count = 0;
        for (auto p : m) {
            max_count = max(max_count, p.second);
        }
        return max_count;
    }
};
