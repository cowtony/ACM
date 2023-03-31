class Solution {
public:
    string maskPII(string s) {
        int at_idx = s.find('@');
        if (at_idx != string::npos) {  // email
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at_idx - 1);
        } else {  // Phone number
            string digits;
            for (char c : s) {
                if (isdigit(c)) {
                    digits += c;
                }
            }
            return (digits.length() > 10? "+" + string(digits.length() - 10, '*') + "-" : "") +
                   "***-***-" + digits.substr(digits.length() - 4);
        }
    }
};
