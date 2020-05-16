class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> rpn;
        stack<string> operators;
        for (const string& token : expression) {
            if (token == "(") {
                operators.push(token);
            } else if (token == ")") {
                while (!operators.empty()) {
                    if (operators.top() == "(") {
                        operators.pop();
                        break;
                    }
                    rpn.push_back(operators.top());
                    operators.pop();
                }
            } else if (token == "+" or token == "-") {
                while (!operators.empty() and operators.top() != "(") {
                    rpn.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
            } else if (token == "*" or token == "/") {
                if (!operators.empty() and (operators.top() == "*" or operators.top() == "/")) {
                    rpn.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
            } else { // Number
                rpn.push_back(token);
            }
        }
        
        while (!operators.empty()) {
            rpn.push_back(operators.top());
            operators.pop();
        }
        
        return rpn;
    }
};
