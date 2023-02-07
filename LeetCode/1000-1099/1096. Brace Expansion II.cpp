set<string> operator+(const set<string>& a, const set<string>& b) {
    set<string> result;
    for (const string& s : a) {
        result.insert(s);
    }
    for (const string& s : b) {
        result.insert(s);
    }
    return result;
}
set<string> operator+=(set<string>& a, const set<string>& b) {
    a = a + b;
    return a;
}
set<string> operator*(const set<string>& a, const set<string>& b) {
    set<string> result;
    for (const string& s1 : a) {
        for (const string& s2 : b) {
            result.insert(s1 + s2);
        }
    }
    return result;
}
set<string> operator*=(set<string>& a, const set<string>& b) {
    a = a * b;
    return a;
}

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        expression.push_back('}');
        reverse(expression.begin(), expression.end());
        auto result = expand(expression);
        return vector<string>(result.begin(), result.end());
    }

    set<string> expand(string& expression) {
        set<string> result;
        set<string> multiply{""};  // = 1
        string word;
        while (!expression.empty()) {
            char c = expression.back();
            expression.pop_back();

            if (isalpha(c)) {
                word += c;
            } else {  // '{', '}', ','
                multiply *= {word};
                word.clear();
                if (c == '{') {
                    multiply *= expand(expression);
                } else {
                    result += multiply;
                    if (c == '}') {
                        return result;
                    } else {  // ','
                        multiply = {""};
                    }
                }
            }
        }
        return {};  // Should never reach here.
    }

};