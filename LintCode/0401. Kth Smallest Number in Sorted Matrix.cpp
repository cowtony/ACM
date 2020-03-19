// LeetCode 378: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Node {
  public:
    Node(int v, int i, int j): val(v), x(i), y(j) {}
    int x;
    int y;
    int val;

    bool operator<(const Node& b) const {
        return val > b.val;
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here
        vector<vector<bool>> used(matrix.size(), vector<bool>(matrix[0].size(), false));
        priority_queue<Node> list;
        list.push(Node(matrix[0][0], 0, 0));
        used[0][0] = true;
        
        for (int i = 1; i < k; i++) {
            Node smallest = list.top();
            list.pop();
            if (smallest.y + 1 < matrix[0].size() and !used[smallest.x][smallest.y + 1]) {
                list.push(Node(matrix[smallest.x][smallest.y + 1], smallest.x, smallest.y + 1));
                used[smallest.x][smallest.y + 1] = true;
            }
            if (smallest.x + 1 < matrix.size() and !used[smallest.x + 1][smallest.y]) {
                list.push(Node(matrix[smallest.x + 1][smallest.y], smallest.x + 1, smallest.y));
                used[smallest.x + 1][smallest.y] = true;
            }
        }
        return list.top().val;
    }
};
