class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        vector<string> ret;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '+' and s[i - 1] == '+') {
                s[i - 1] = '-';
                s[i] = '-';
                ret.push_back(s);
                s[i - 1] = '+';
                s[i] = '+';
            }
        }
        return ret;
    }
};
