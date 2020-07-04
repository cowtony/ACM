class Solution {
public:
    /**
     * @param str: the prefix notation.
     * @return: return the postfix notation.
     */
    vector<string> split(string s, string delimiter) {
        vector<string> res;
        size_t p = 0;
        while (p <= s.length()) {
            size_t pos = s.find(delimiter, p);
            if (pos == string::npos) {
                pos = s.length();
            }
            res.emplace_back(s.substr(p, pos - p));
            p = pos + delimiter.length();
        }
        return res;
    }
    
    bool isOperator(string c) {
        return c == "+" or c == "-" or c == "*" or c == "/";
    }
    
    string prefixNotationToPostfixNotation(string &str) {
        stack<string> s;
        for (string c : split(str, " ")) {
            if (isOperator(c)) {
                s.push(c);
            } else {
                string right = c;
                while (!s.empty() and !isOperator(s.top())) {
                    string left = s.top();
                    s.pop();
                    string operation = s.top();
                    s.pop();
                    right = left + " " + right + " " + operation;
                }
                s.push(right);
            }
        }
        return s.top();
    }
};
