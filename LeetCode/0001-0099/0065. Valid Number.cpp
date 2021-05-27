class Solution {
public:
    bool isNumber(string s) {
        while (!s.empty() and s.front() == ' ') {
            s.erase(s.begin());
        }
        while (!s.empty() and s.back() == ' ') {
            s.pop_back();
        }
        if (s.empty()) {
            return false;
        }
        if (s.find("e") != -1) {
            string left = s.substr(0, s.find("e"));
            string right = s.substr(s.find("e") + 1);
            return isDecimal(left) and isInt(right);
        } else {
            return isDecimal(s);
        }
        return false;
    }
    
    bool isDecimal(string s) {
        if (s.find('.') != -1) {
            if (s.find('.') < s.length() - 1 and !isDigit(s[s.find('.') + 1])) {
                return false;
            }
            s.erase(s.find('.'), 1);
        }
        cout << s << s << endl;
        return isInt(s);
    }
    bool isInt(string s) {
        if (s.empty()) {
            return false;
        }
        if (s.front() == '-' or s.front() == '+') {
            s.erase(s.begin());
        }
        if (s.empty()) {
            return false;
        }
        for (char c : s) {
            if (!isDigit(c)) {
                return false;
            }
        }
        return true;
    }
    bool isDigit(char c) {
        return c >= '0' and c <= '9';
    }
    
};
