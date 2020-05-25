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
            if (priority(token) > 0) {
                while (s.size() >= 3) {
                    ExpressionTreeNode* right = s.top();
                    if (right->symbol == "(") { return nullptr; }
                    s.pop();
                    
                    ExpressionTreeNode* mid = s.top();
                    if (priority(token) > priority(mid->symbol)) {
                        s.push(right);
                        break;
                    }
                    s.pop();
                    
                    ExpressionTreeNode* left = s.top();
                    if (left->symbol == "(") { return nullptr; }
                    s.pop();
                    
                    mid->left = left;
                    mid->right = right;
                    s.push(mid);
                }
                if (token == ")") {
                    ExpressionTreeNode* node = s.top();
                    s.pop();
                    delete s.top();
                    s.pop();
                    s.push(node);
                } else {
                    s.push(new ExpressionTreeNode(token));
                }
            } else { // Number or "("
                s.push(new ExpressionTreeNode(token));
            }
        }
        return s.top();
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
