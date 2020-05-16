class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        int i = 0, j = 0;
        bool edited;
        while (i < s.length() or j < t.length()) {
            if (i < s.length() and j < t.length() and s[i] == t[j]) {
                i++;
                j++;
            } else {
                if (!edited and s.length() < t.length()) {
                    j++;
                    edited = true;
                } else if (!edited and s.length() > t.length()) {
                    i++;
                    edited = true;
                } else if (!edited and s.length() == t.length()) {
                    i++;
                    j++;
                    edited = true;
                } else {
                    return false;
                }
            }
        }
        return edited;
    }
};
