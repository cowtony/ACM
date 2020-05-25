class Solution {
public:
    /**
     * @param expression: a list of strings
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        if (expression.empty()) {
            return 0;
        }
        const unordered_map<string, function<int(int, int)>> func = {
            {"+", [](int a, int b){ return a + b; } },
            {"-", [](int a, int b){ return a - b; } },
            {"*", [](int a, int b){ return a * b; } },
            {"/", [](int a, int b){ return a / b; } },
        };
        
        expression.insert(expression.begin(), "(");
        expression.push_back(")");
        stack<string> s;
        for (const string& token : expression) {
            if (priority(token) > 0) {
                while (s.size() >= 3) {
                    string right = s.top();
                    if (right == "(") { return 0; }
                    s.pop();
                    
                    string mid = s.top();
                    if (priority(token) > priority(mid)) {
                        s.push(right);
                        break;
                    }
                    s.pop();
                    
                    string left = s.top();
                    if (left == "(") { return 0; }
                    s.pop();
                    
                    s.push(to_string(func.at(mid)(stoi(left), stoi(right))));
                }
                if (token == ")") {
                    string node = s.top();
                    s.pop();
                    s.pop();
                    s.push(node);
                } else {
                    s.push(token);
                }
            } else { // Number or "("
                s.push(token);
            }
        }
        return stoi(s.top());
    }
    
    int priority(string s) {
        if (s == "(") {
            return 0;
        } else if (s == ")") {
            return 1;
        } else if (s == "+" or s == "-") {
            return 2;
        } else if (s == "*" or s == "/") {
            return 3;
        } else {
            return -1;
        }
    }
};
