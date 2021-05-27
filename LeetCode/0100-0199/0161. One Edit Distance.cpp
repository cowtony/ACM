class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int i = 0, j = 0;
        bool edited = false;
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
