// Reference: https://www.cnblogs.com/grenet/p/3145800.html
// Reference: https://www.cnblogs.com/grenet/p/3163550.html
class DancingLinks {
    struct Node {
        Node(int c) : col(c) {
            column = up = down = left = right = this;
            element_count = 0;
        }
        Node* column;
        Node* up;
        Node* down;
        Node* left;
        Node* right;
        int col;
        int element_count; // For optimization.
    };
    
  public:
    DancingLinks(int col_count) {
        head = new Node(0);
        column_nodes.push_back(head);
        // Index 0 is the head, 1 to col is each column.
        Node *pre_node = head;
        for (int i = 1; i <= col_count; i++) {
            Node* node = new Node(i);
            column_nodes.push_back(node);
            node->left = pre_node;
            pre_node->right = node;
            pre_node = node;
        }
        head->left = pre_node;
        pre_node->right = head;
    }
    ~DancingLinks() {
        delete head; // This is not enough.
    }
    
    void appendRow(set<int> columns) {
        Node* dummy = new Node(0);
        Node* pre_node = dummy;
        for (int col : columns) {
            Node* node = new Node(col);
            node->column = column_nodes[col];
            node->column->element_count++;
            // Vertical:
            node->up = node->column->up;
            node->down = node->column;
            node->column->up->down = node;
            node->column->up = node;
            // Horizontal:
            pre_node->right = node;
            node->left = pre_node;
            pre_node = node;
        }
        // Complete the horizontal circle.
        pre_node->right = dummy->right;
        dummy->right->left = pre_node;
        delete dummy;
    }
    
    void appendSolutionRow(set<int> columns) {
        // solution.emplace_back(columns);
        for (int num : columns) {
            removeColumn(column_nodes[num]);
        }
    }
    
    bool dance() {
        if(head->right == head) {
            return true;
        }
        
        // optimization: Start from the column has minimum 1s.
        int min_count = INT_MAX;
        Node* C1;
        Node* column_node = head->right;
        while (column_node != head) {
            if (column_node->element_count == 0) {
                return false;
            } else if (column_node->element_count < min_count) {
                min_count = column_node->element_count;
                C1 = column_node;
            }
            column_node = column_node->right;
        }
 
        removeColumn(C1);
        
        Node* vertical = C1->down;
        while (vertical != C1) {
            set<int> row_data;
            row_data.insert(vertical->col);
            Node* horizontal = vertical->right;
            while (horizontal != vertical) {
                row_data.insert(horizontal->col);
                removeColumn(horizontal->column);
                horizontal = horizontal->right;
            }
            solution.push_back(row_data);
            if(dance()) {
                return true;
            } 
            horizontal = vertical->left;
            while (horizontal != vertical) {
                restoreColumn(horizontal->column);
                horizontal = horizontal->left;
            }
            solution.pop_back();
            vertical = vertical->down;
        }
        restoreColumn(C1);
 
        return false;
    }
    
    vector<set<int>> solution; // Store all the rows and columns has node.
    
  private:
    Node* head;
    vector<Node*> column_nodes;
    
    void removeColumn(Node* col_node) {
        col_node = col_node->column; // In case not send in the top row.
        col_node->right->left = col_node->left;
        col_node->left->right = col_node->right;
        
        Node* vertical = col_node->down;
        while (vertical != col_node) {
            Node* horizontal = vertical->right;
            while (horizontal != vertical) {
                horizontal->down->up = horizontal->up;
                horizontal->up->down = horizontal->down;
                horizontal = horizontal->right;
            }
            vertical = vertical->down;
        }
    }
    void restoreColumn(Node* col_node) {
        col_node = col_node->column; // In case not send in the top row.
        col_node->right->left = col_node;
        col_node->left->right = col_node;
        
        Node* vertical = col_node->up;
        while (vertical != col_node) {
            Node* horizontal = vertical->right;
            while (horizontal != vertical) {
                horizontal->down->up = horizontal;
                horizontal->up->down = horizontal;
                horizontal = horizontal->right;
            }
            vertical = vertical->up;
        }
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // First 9 * 9 columns: row i & column j has a number.
        // Second 9 * 9 columns: row i has number j.
        // Third 9 * 9 columns: col i has number j.
        // Forth 9 * 9 columns: sub-box i has number j.
        
        DancingLinks dlx(4 * 9 * 9);

        // Construct the matrix.
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int num = board[i][j] - '0';
                    for (int num = 1; num <= 9; num++) {
                        dlx.appendRow({0 * 9 * 9 + i * 9 + j + 1, 
                                       1 * 9 * 9 + i * 9 + num,
                                       2 * 9 * 9 + j * 9 + num,
                                       3 * 9 * 9 + (i / 3 * 3 + j / 3) * 9 + num});
                    }
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    dlx.appendSolutionRow({0 * 9 * 9 + i * 9 + j + 1, 
                                           1 * 9 * 9 + i * 9 + num,
                                           2 * 9 * 9 + j * 9 + num,
                                           3 * 9 * 9 + (i / 3 * 3 + j / 3) * 9 + num});
                } 
            }
        }
        
        dlx.dance();
        
        for (const set<int>& row : dlx.solution) {
            int i, j, num;
            parseSolution(row, i, j, num);
            board[i][j] = num + '0';
        }
    }
    
    void parseSolution(set<int> nums, int& row, int & col, int& num) {
        row = (*nums.begin() - 1) / 9;
        col = (*nums.begin() - 1) % 9;
        nums.erase(nums.begin());
        num = *nums.begin() - 81 - row * 9;
    }
};
