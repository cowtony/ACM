class Solution {
public:
    /**
     * @param s: a string
     * @return: return a integer
     */
    int titleToNumber(string &s) {
        int result = 0;
        while (!s.empty())
        {
            result *= 26;
            result += s.front() - 'A' + 1;
            s.erase(s.begin());
        }
        return result;
    }
};
