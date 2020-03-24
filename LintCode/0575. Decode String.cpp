class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        stack<char> c_stack;
        for (char c : s) {
            if (c == ']') {
                string temp;
                while (c_stack.top() != '[') {
                    temp = c_stack.top() + temp;
                    c_stack.pop();
                }
                c_stack.pop(); // '['
                
                string repeat;
                while (!c_stack.empty() and c_stack.top() >= '0' and c_stack.top() <= '9') {
                    repeat = c_stack.top() + repeat;
                    c_stack.pop();
                }
                
                for (int i = 0; i < stoi(repeat); i++) {
                    for (char t : temp) {
                        c_stack.push(t);
                    }
                }
            } else {
                c_stack.push(c);
            }
        }
        string ans;
        while (!c_stack.empty()) {
            ans = c_stack.top() + ans;
            c_stack.pop();
        }
        return ans;
    }
};
