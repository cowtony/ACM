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
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<Node> pq;
        
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        for (int i = 0; i < rows; i++) {
            pq.push(Node(i, 0, heightMap[i][0]));
            heightMap[i][0] = -1;
            pq.push(Node(i, cols - 1, heightMap[i][cols - 1]));
            heightMap[i][cols - 1] = -1;
        }
        for (int j = 1; j < cols - 1; j++) {
            pq.push(Node(0, j, heightMap[0][j]));
            heightMap[0][j] = -1;
            pq.push(Node(rows - 1, j, heightMap[rows - 1][j]));
            heightMap[rows - 1][j] = -1;
        }
        
        const vector<vector<int>> kMove = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int water = 0;
        while (!pq.empty()) {
            Node n = pq.top();
            pq.pop();
            for (auto move : kMove) {
                int i = n.row + move[0];
                int j = n.col + move[1];
                if (!isValid(heightMap, i, j)) {
                    continue;
                }
                water += max(0, n.store - heightMap[i][j]);
                pq.push(Node(i, j, max(heightMap[i][j], n.store)));
                heightMap[i][j] = -1;
            }
        }
        return water;
    }
    
    bool isValid(vector<vector<int>>& heightMap, int i, int j) {
        if (i < 0 or i >= heightMap.size()) {
            return false;
        }
        if (j < 0 or j >= heightMap[0].size()) {
            return false;
        }
        return heightMap[i][j] >= 0;
    }
};
