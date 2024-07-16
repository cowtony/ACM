// Floyd Warshall O(V^3)
void floyd(vector<vector<int>>& adjacency_matrix) {
    for(int k = 0; k < adjacency_matrix.size(); k++) {
        for(int i = 0; i < adjacency_matrix.size(); i++) {
            for(int j = 0; j < adjacency_matrix.size(); j++) {
                adjacency_matrix[i][j] = min(adjacency_matrix[i][j], adjacency_matrix[i][k] + adjacency_matrix[k][j]);
            }
        }
    }
}

// Check if graph has cycle
bool hasCycle(const vector<vector<int>>& adjacency_list, vector<bool>& visited, int node = 0) {
    if (node < 0 or node >= visited.size()) {
        return false;
    }
    if (visited[node]) {
        return true;
    }
    visited[node] = true;
    for (int next : adjacency_list.at(node)) {
        if (hasCycle(adjacency_list, visited, next)) {
            return true;
        }
    }
    return visited[node] = false;
}
