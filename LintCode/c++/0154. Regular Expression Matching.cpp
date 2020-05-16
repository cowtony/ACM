class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        
        bool first_match = !s.empty() and (p.front() == s.front() or p.front() == '.');
        
        if (p.length() > 1 and p[1] == '*') {
            if (first_match) {
                return isMatch(s.substr(1), p) or isMatch(s, p.substr(2));
            } else {
                return isMatch(s, p.substr(2));
            }
        }
        
        return first_match and isMatch(s.substr(1), p.substr(1));
    }
};
