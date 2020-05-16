// LeetCode 407: https://leetcode.com/problems/trapping-rain-water-ii/
struct Node {
    Node(int i, int j, int height) : row(i), col(j), store(height) {}
    int row;
    int col;
    int store;
    
    bool operator<(const Node& n) const {
        return store > n.store;
    }
};

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        priority_queue<Node> pq;
        
        for (int i = 0; i < heights.size(); i++) {
            pq.push(Node(i, 0, heights[i][0]));
            heights[i][0] = -1;
            pq.push(Node(i, heights[0].size() - 1, heights[i][heights[0].size() - 1]));
            heights[i][heights[0].size() - 1] = -1;
        }
        for (int j = 1; j < heights[0].size() - 1; j++) {
            pq.push(Node(0, j, heights[0][j]));
            heights[0][j] = -1;
            pq.push(Node(heights.size() - 1, j, heights[heights.size() - 1][j]));
            heights[heights.size() - 1][j] = -1;
        }
        
        const vector<vector<int>> kMove = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int water = 0;
        while (!pq.empty()) {
            Node n = pq.top();
            pq.pop();
            for (auto move : kMove) {
                int i = n.row + move[0];
                int j = n.col + move[1];
                if (!isValid(heights, i, j)) {
                    continue;
                }
                water += max(0, n.store - heights[i][j]);
                pq.push(Node(i, j, max(heights[i][j], n.store)));
                heights[i][j] = -1;
            }
        }
        return water;
    }
    
    bool isValid(vector<vector<int>>& heights, int i, int j) {
        if (i < 0 or i >= heights.size()) {
            return false;
        }
        if (j < 0 or j >= heights[0].size()) {
            return false;
        }
        return heights[i][j] >= 0;
    }
    
};
