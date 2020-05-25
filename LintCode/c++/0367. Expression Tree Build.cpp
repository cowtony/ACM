/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode * build(vector<string> &expression) {
        expression.insert(expression.begin(), "(");
        expression.push_back(")");
        stack<ExpressionTreeNode*> s;
        for (const string& token : expression) {
            if (token == "(") {
                s.push(nullptr); // Use nullptr to represent "(", no need to delete later.
            } else if (token == ")") {
                while (!s.empty()) {
                    ExpressionTreeNode* right = s.top();
                    if (!right) { return nullptr; }
                    s.pop();
                    
                    ExpressionTreeNode* mid = s.top();
                    s.pop();
                    if (!mid) {
                        s.push(right);
                        break;
                    }
                    
                    ExpressionTreeNode* left = s.top();
                    if (!left) { return nullptr; }
                    s.pop();
                    
                    mid->left = left;
                    mid->right = right;
                    s.push(mid);
                }
            } else if (token == "*" or token == "/") {
                s.push(new ExpressionTreeNode(token));
            } else if (token == "+" or token == "-") {
                while (s.size() >= 3) {
                    ExpressionTreeNode* right = s.top();
                    if (!right) { return nullptr; }
                    s.pop();
                    
                    ExpressionTreeNode* mid = s.top();
                    if (!mid) {
                        s.push(right);
                        break;
                    }
                    s.pop();
                    
                    ExpressionTreeNode* left = s.top();
                    if (!left) { return nullptr; }
                    s.pop();
                    
                    mid->left = left;
                    mid->right = right;
                    s.push(mid);
                }
                s.push(new ExpressionTreeNode(token));
            } else {  // Number
                ExpressionTreeNode* right = new ExpressionTreeNode(token);
                if (s.size() >= 3 and s.top() and (s.top()->symbol == "*" or s.top()->symbol == "/")) {
                    ExpressionTreeNode* mid = s.top();
                    s.pop();
                    ExpressionTreeNode* left = s.top();
                    if (!left) {
                        return nullptr;
                    }
                    s.pop();
                    mid->left = left;
                    mid->right = right;
                    s.push(mid);
                } else {
                    s.push(right);
                }
            }
        }
        
        return s.top();
    }
};
