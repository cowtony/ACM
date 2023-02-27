/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        vector<vector<int>> prefix_sum(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                prefix_sum[r + 1][c + 1] = prefix_sum[r][c + 1] + prefix_sum[r + 1][c] - 
                                           prefix_sum[r][c] + grid[r][c];
            }
        }

        return construct(prefix_sum, 0, 0, grid.size(), grid.size());
    }

    Node* construct(const vector<vector<int>>& prefix_sum, int r1, int c1, int r2, int c2) {
        int sum = prefix_sum[r2][c2] - prefix_sum[r1][c2] - prefix_sum[r2][c1] + prefix_sum[r1][c1];
        if (sum == (r2 - r1) * (c2 - c1) || sum == 0) {
            return new Node(sum > 0, true);
        }
        int r_mid = r1 + (r2 - r1) / 2;
        int c_mid = c1 + (c2 - c1) / 2;
        return new Node(true, false,
            construct(prefix_sum, r1, c1, r_mid, c_mid),
            construct(prefix_sum, r1, c_mid, r_mid, c2),
            construct(prefix_sum, r_mid, c1, r2, c_mid),
            construct(prefix_sum, r_mid, c_mid, r2, c2));
    }

};
