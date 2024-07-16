class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> adjacency_matrix(n, vector<int>(n, INT_MAX >> 1));
        for (const auto& road : roads) {
            adjacency_matrix[road[0]][road[1]] = min(adjacency_matrix[road[0]][road[1]], road[2]);
            adjacency_matrix[road[1]][road[0]] = min(adjacency_matrix[road[1]][road[0]], road[2]);
        }

        int result = 0;
        for (int mask = (1 << n) - 1; mask >= 0; mask--) {
            auto matrix_copy = adjacency_matrix;
            floyd(matrix_copy, mask);
            if (getMaxDistance(matrix_copy, mask) <= maxDistance) {
                result++;
            }
        }
        return result;
    }

    void floyd(vector<vector<int>>& adjacency_matrix, int mask) {
        for(int k = 0; k < adjacency_matrix.size(); k++) {
            if (mask & (1 << k)) {
                continue;
            }
            for(int i = 0; i < adjacency_matrix.size(); i++) {
                if (i == k || mask & (1 << i)) {
                    continue;
                }
                for(int j = 0; j < adjacency_matrix.size(); j++) {
                    if (j == i || mask & (1 << j)) {
                        continue;
                    }
                    adjacency_matrix[i][j] = min(adjacency_matrix[i][j], adjacency_matrix[i][k] + adjacency_matrix[k][j]);
                }
            }
        }
    }

    int getMaxDistance(const vector<vector<int>>& adjacency_matrix, int mask) {
        int result = 0;
        for (int i = 0; i < adjacency_matrix.size(); i++) {
            if (mask & (1 << i)) {
                continue;
            }
            for (int j = i + 1; j < adjacency_matrix.size(); j++) {
                if (mask & (1 << j)) {
                    continue;
                }
                result = max(result, adjacency_matrix[i][j]);
            }
        }
        return result;
    }
};
