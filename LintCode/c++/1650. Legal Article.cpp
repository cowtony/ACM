class Solution {
public:
    /**
     * @param s: the article
     * @return: the number of letters that are illegal
     */
    int count(string &s) {
        bool capital = true;
        int error = 0;
        char pre = '.';
        for (char c : s) {
            if (isLetter(c)) {
                if (capital and !isCapital(c)) {
                    error++;
                }
                if (isLetter(pre) and isCapital(c)) {
                    error++;
                }
                capital = false;
            } else if (c == '.') {
                capital = true;
            }
            pre = c;
        }
        return error;
    }
    
    bool isLetter(char c) {
        return c >= 'a' and c <= 'z' or c >= 'A' and c <= 'Z';
    }
    bool isCapital(char c) {
        return c >= 'A' and c <= 'Z';
    }
    
};
