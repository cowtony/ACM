/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        if (!root) {
            return "{}";
        }
        string s;
        queue<TreeNode*> q;
        q.push(root);
        s += to_string(root->val) + ",";
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                q.push(node->left);
                if (node->left) {
                    s += to_string(node->left->val) + ",";
                } else {
                    s += "#,";
                }
                q.push(node->right);
                if (node->right) {
                    s += to_string(node->right->val) + ",";
                } else {
                    s += "#,";
                }
            }
        }
        cout << "{" + s.substr(0, s.length() - 1) + "}" << endl;
        return "{" + s.substr(0, s.length() - 1) + "}";
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        data = data.substr(1, data.length() - 2) + ",";
        queue<TreeNode*> q;
        string s = data.substr(0, data.find(','));
        data = data.substr(data.find(',') + 1);
        TreeNode* root = createNode(s);
        q.push(root);
        
        while (!data.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                continue;
            }
            string s = data.substr(0, data.find(','));
            data = data.substr(data.find(',') + 1);
            node->left = createNode(s);
            q.push(node->left);
            
            s = data.substr(0, data.find(','));
            data = data.substr(data.find(',') + 1);
            node->right = createNode(s);
            q.push(node->right);
        }
        
        return root;
    }
    
private:
    TreeNode* createNode(string s) {
        if (s == "#" or s.empty()) {
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(stoi(s));
            return node;
        }
    }
};
