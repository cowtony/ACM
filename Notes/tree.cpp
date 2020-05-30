struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Traversal.
void recursiveTreeTraversal(TreeNode* root, std::function<void(TreeNode*)> func) {
    if (!root) { return; }
    // func(root); // Preorder
    if (root->left) { recursiveTreeTraversal(root->left, func); }
    // func(root);  // Inorder
    if (root->right) { recursiveTreeTraversal(root->right, func); }
    // func(root);  // Postorder
}

// Morris Traversal.
void morrisTraversalInOrder(TreeNode* root, std::function<void(TreeNode*)> func) {
    while (root) {  
        if (!root->left) {  
            func(root);
            root = root->right;  
        } else {  
            TreeNode* pre = root->left;  
            while (pre->right && pre->right != root) {
                pre = pre->right;  
            }  
            if (!pre->right) { 
                pre->right = root;
                root = root->left;  
            } else {  
                pre->right = nullptr;  
                func(root);
                root = root->right;  
            }  
        }  
    }
}

// Create Balanced Binary Search Tree from sorted array.
template<class Iterator>
TreeNode* createBalancedBST(const Iterator& begin, const Iterator& end) {
    if (begin == end) { return nullptr; }
    int size = std::distance(begin, end);
    Iterator mid = std::next(begin, size / 2);
    TreeNode* root = new TreeNode(*mid);
    root->left = createBalancedBST(begin, mid);
    root->right = createBalancedBST(mid + 1, end);
    return root;
}
