class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        const unordered_map<string, function<int(int, int)>> func = {
            {"+", [](int a, int b){ return a + b; } },
            {"-", [](int a, int b){ return a - b; } },
            {"*", [](int a, int b){ return a * b; } },
            {"/", [](int a, int b){ return a / b; } },
        };
        
        stack<int> s;
        for (const string& token : tokens) {
            if (func.find(token) != func.end()) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(func.at(token)(a, b));
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
