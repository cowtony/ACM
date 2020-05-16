class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &expression) {
        reverse(expression.begin(), expression.end());
        
        vector<string> pn;
        stack<string> operators;
        for (const string& token : expression) {
            if (token == ")") {
                operators.push(token);
            } else if (token == "*" or token == "/") {
                operators.push(token);
            } else if (token == "(") {
                while (!operators.empty()) {
                    if (operators.top() == ")") {
                        operators.pop();
                        break;
                    }
                    pn.push_back(operators.top());
                    operators.pop();
                }
            } else if (token == "+" or token == "-") {
                while (!operators.empty() and operators.top() != ")" and (operators.top() == "*" or operators.top() == "/")) {
                    pn.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
            } else { // Number
                pn.push_back(token);
            }
        }
        
        while (!operators.empty()) {
            pn.push_back(operators.top());
            operators.pop();
        }
        
        reverse(pn.begin(), pn.end());
        return pn;
    }
};
