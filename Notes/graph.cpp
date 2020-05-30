// Floyd shortest path.
vector<vector<int>> floyd(vertex, vector<int>(vertex, INT_MAX / 2));
// Need to prepare edges here.
for (int k = 0; k < floyd.size(); k++) {
    for (int i = 0; i < floyd.size(); i++) {
        for (int j = 0; j < floyd.size(); j++) {
            if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
                floyd[i][j] = floyd[i][k] + floyd[k][j];
            }
        }
    }
}

// Dijkstra.
