class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) {
            graph[i][i] = 0;
        }
        for (const auto& edge : edges) {
            graph[edge[0]][edge[1]] = min(graph[edge[0]][edge[1]], edge[2]);
            graph[edge[1]][edge[0]] = min(graph[edge[1]][edge[0]], edge[2]);
        }

        floyd(graph);

        int result = 0;
        int node_count = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = count_if(graph[i].begin(), graph[i].end(), [distanceThreshold](int dist) {
                return dist <= distanceThreshold;
            });
            if (count <= node_count) {
                result = i;
                node_count = count;
            }
        }
        return result;
    }

    void floyd(vector<vector<int>>& adjacency_matrix) {
        for(int k = 0; k < adjacency_matrix.size(); k++) {
            for(int i = 0; i < adjacency_matrix.size(); i++) {
                for(int j = 0; j < adjacency_matrix.size(); j++) {
                    adjacency_matrix[i][j] = min(adjacency_matrix[i][j], adjacency_matrix[i][k] + adjacency_matrix[k][j]);
                }
            }
        }
    }
};
