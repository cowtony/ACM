// Floyd Warshall O(V^3)
void floyd(vector<vector<int>>& adjacency_matrix) {
    for(int k = 0; k < 26; k ++) {
        for(int i = 0; i < 26; i ++) {
            for(int j = 0; j < 26; j ++) {
                adjacency_matrix[i][j] = min(adjacency_matrix[i][j], adjacency_matrix[i][k] + adjacency_matrix[k][j]);
            }
        }
    }
}

// Dijkstra O((E+V)log(V))
template<class V, class W>
unordered_map<V, W> dijkstra(const unordered_map<V, vector<pair<W, V>>>& edges, int from) {
    unordered_map<V, W> distance;
    distance[from] = 0;
    unordered_map<V, V> previous;

    priority_queue<pair<W, V>, vector<pair<W, V>>, greater<pair<W, V>>> pq;
    pq.push({0, from});
    while (!pq.empty()) {
        int next = pq.top().second;
        pq.pop();

        if (edges.find(next) == edges.end() or distance.find(next) == distance.end()) {
            continue;
        }
        for (const auto& edge : edges.at(next)) {
            if (distance.find(edge.second) == distance.end() or distance[edge.second] > distance[next] + edge.first) {
                distance[edge.second] = distance[next] + edge.first;
                pq.push(edge);
            }
        }
    }
    return distance;
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
