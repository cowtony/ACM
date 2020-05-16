class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        map<char, int> m;
        for (char c : str) {
            m[c]++;
        }
        for (auto p : m) {
            if (p.second == 1) {
                return p.first;
            }
        }
    }
};
