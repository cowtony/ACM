/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
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

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
