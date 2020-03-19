// LeetCode 373: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
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
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
        // write your code here
        if (A.empty() or B.empty()) {
            return{};
        }
        vector<vector<bool>> used(A.size(), vector<bool>(B.size(), false));
        priority_queue<Node> list;
        list.push(Node(A[0] + B[0], 0, 0));
        used[0][0] = true;
        
        for (int i = 1; i < k and !list.empty(); i++) {
            Node smallest = list.top();
            list.pop();
            if (smallest.y + 1 < B.size() and !used[smallest.x][smallest.y + 1]) {
                list.push(Node(A[smallest.x] + B[smallest.y + 1], smallest.x, smallest.y + 1));
                used[smallest.x][smallest.y + 1] = true;
            }
            if (smallest.x + 1 < A.size() and !used[smallest.x + 1][smallest.y]) {
                list.push(Node(A[smallest.x + 1] + B[smallest.y], smallest.x + 1, smallest.y));
                used[smallest.x + 1][smallest.y] = true;
            }
        }
        return list.top().val;
    }
};
